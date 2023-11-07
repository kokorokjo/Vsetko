package main

import (
	"fmt"
	"github.com/trojsten/ksp-proboj/libproboj"
	"math"
	"math/rand"
)

type World struct {
	Runner          libproboj.Runner
	Players         []Player         `json:"players"`
	PlayerMovements []PlayerMovement `json:"-"`
	Bullets         []Bullet         `json:"bullets"`
	BulletMovements []BulletMovement `json:"-"`
	Entities        []Entity         `json:"entities"`
	DiedOrder       []Player         `json:"-"`
	MinX            float32          `json:"min_x"`
	MaxX            float32          `json:"max_x"`
	MinY            float32          `json:"min_y"`
	MaxY            float32          `json:"max_y"`
	TickNumber      int              `json:"tick_number"`
	BulletNumber    int              `json:"-"`
}

func aliveInt(alive bool) int {
	if alive {
		return 1
	}
	return 0
}

// Running returns whether the game is still running
func (w *World) Running() bool {
	alivePlayers := 0
	for _, player := range w.Players {
		if player.Alive {
			alivePlayers++
		}
	}
	return alivePlayers >= 2
}

func (w *World) SpawnEntityPosition(p *Position) {
	p.X = rand.Float32()*(w.MaxX-w.MinX) + w.MinX
	p.Y = rand.Float32()*(w.MaxY-w.MinY) + w.MinY
}

func (w *World) SpawnPlayerPosition(p *Position) {
	var x = rand.Float32()*(w.MaxX-w.MinX) + w.MinX
	var y = rand.Float32()*(w.MaxY-w.MinY) + w.MinY
	var dist = w.NearestPlayerDistance(Position{X: x, Y: y})
	for i := 0; i < SpawnIterations; i++ {
		var x2 = rand.Float32()*(w.MaxX-w.MinX) + w.MinX
		var y2 = rand.Float32()*(w.MaxY-w.MinY) + w.MinY
		var dist2 = w.NearestPlayerDistance(Position{X: x2, Y: y2})
		if dist < dist2 {
			x = x2
			y = y2
			dist = dist2
		}
	}
	p.X = x
	p.Y = y
}

func (w *World) NearestPlayerDistance(p Position) float32 {
	var minDistance = float32(math.Inf(1))
	for _, player := range w.AlivePlayers() {
		minDistance = Min(minDistance, player.Distance(p))
	}
	return minDistance
}

func (w *World) SpawnEntity() {
	var entity = w.NewEntity()
	w.SpawnEntityPosition(&entity.Position)
	w.Runner.Log(fmt.Sprintf("spawned entity on (%f, %f)", entity.Position.X, entity.Position.Y))
	w.Entities = append(w.Entities, entity)
}

// AlivePlayers returns a list of currently alive players
func (w *World) AlivePlayers() (players []*Player) {
	for i, player := range w.Players {
		if player.Alive {
			players = append(players, &w.Players[i])
		}
	}
	return
}

func (w *World) CalculateCG() Position {
	var x, y float32
	count := 0
	for _, player := range w.Players {
		if player.Alive {
			x += player.X
			y += player.Y
			count += 1
		}
	}
	if count == 0 {
		return Position{X: 0, Y: 0}
	}

	return Position{
		X: x / float32(count),
		Y: y / float32(count),
	}
}

func (w *World) Shrink() {
	if w.TickNumber > ShrinkWorldAfter && (w.MaxX > MinWorldSize || w.TickNumber > GameEnd){
		w.Runner.Log(fmt.Sprintf("Shrinking world"))
		w.MinX += WorldSizeShrink
		w.MaxX -= WorldSizeShrink
		w.MinY += WorldSizeShrink
		w.MaxY -= WorldSizeShrink
		if w.MinX > w.MaxX && w.MinY > w.MaxY {
			w.MaxX = 0
			w.MinX = 0
			w.MaxY = 0
			w.MinY = 0
		}
	}
}
