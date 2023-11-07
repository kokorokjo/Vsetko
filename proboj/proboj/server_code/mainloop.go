package main

import (
	"encoding/json"
	"fmt"
	"github.com/trojsten/ksp-proboj/libproboj"
	"time"
)

// Tick executes one game tick
func (w *World) Tick() {
	w.PlayerMovements = nil
	w.BulletMovements = nil
	communicate(w)

	tickBullets(w)
	tickPlayers(w)
	addNotRunningPlayers(w)

	// Collisions
	collisionsPlayerEntity(w)
	collisionsPlayerBullet(w)
	collisionsPlayerPlayer(w)
	collisionsEntityBullet(w)
	despawnEntities(w)

	observe(w)
}

type playerTurn struct {
	player *Player
	data   string
}

func addNotRunningPlayers(w *World) {
	for _, player := range w.Players {
		if player.Alive && !player.Running {
			playerMovement := player.MoveTo(player.X, player.Y)
			w.PlayerMovements = append(w.PlayerMovements, playerMovement)
		}
	}
}

// communicate sends data to players and parse their responses
func communicate(w *World) {
	w.Runner.Log(fmt.Sprintf("TICK %d", w.TickNumber))
	var turns []playerTurn

	// Firstly, send data to players and read their turns
	for _, player := range w.AlivePlayers() {
		if !player.Running {
			turns = append(turns, playerTurn{player, ""})
		}
		sendData := w.DataForPlayer(*player)
		w.Runner.ToPlayer(player.Name, fmt.Sprintf("TICK %d", w.TickNumber), sendData)

		start := time.Now()
		resp, data := w.Runner.ReadPlayer(player.Name)
		end := time.Now()
		if resp != libproboj.Ok {
			w.Runner.Log(fmt.Sprintf("proboj error while reading from %s: %d", player.Name, resp))
			player.Running = false
			continue
		}
		w.Runner.Log(fmt.Sprintf("player %s responded in %d us", player.Name, end.Sub(start).Microseconds()))
		player.Statistics.TimeOfResponses += end.Sub(start).Microseconds()

		turns = append(turns, playerTurn{player, data})
	}

	// Then, execute their turns
	for _, turn := range turns {
		err := w.ParseResponse(turn.data, turn.player)
		if err != nil {
			w.Runner.Log(fmt.Sprintf("parsing error while parsing response from %s: %s", turn.player.Name, err.Error()))
			continue
		}
	}
}

// observe sends the current world state to the observer
func observe(w *World) {
	data, err := json.Marshal(w)
	if err != nil {
		w.Runner.Log(fmt.Sprintf("could not marshal data for observer: %s", err.Error()))
	}
	w.Runner.ToObserver(string(data))
}

// tickBullets moves all bullets in the game by one tick
func tickBullets(w *World) {
	bullets := []Bullet{}
	for i := range w.Bullets {
		bullet := &w.Bullets[i]
		if success, bulletMovement := bullet.Tick(); success {
			bullets = append(bullets, *bullet)
			w.BulletMovements = append(w.BulletMovements, bulletMovement)
		}
	}
	w.Bullets = bullets
}

// tickPlayers ticks all alive players
func tickPlayers(w *World) {
	for _, player := range w.AlivePlayers() {
		player.Tick()
	}
}

// despawnEntities despawns entities that are too small
func despawnEntities(w *World) {
	entities := []Entity{}
	for i := range w.Entities {
		entity := &w.Entities[i]
		if entity.Health > 0 {
			entities = append(entities, *entity)
		}
	}
	w.Entities = entities
}
