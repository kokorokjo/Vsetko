package main

import (
	"fmt"
	"github.com/trojsten/ksp-proboj/libproboj"
	"math"
	"math/rand"
	"time"
)

func main() {
	runner := libproboj.NewRunner()
	seed := time.Now().UnixMilli()
	rand.Seed(seed)
	runner.Log(fmt.Sprintf("seed %d", seed))

	world := World{Runner: runner, MinX: MinX, MaxX: MaxX, MinY: MinY, MaxY: MaxY, Bullets: []Bullet{}}
	players, _ := runner.ReadConfig()
	for i, player := range players {
		pl := world.NewPlayer(player)
		pl.Id = i
		world.SpawnPlayerPosition(&pl.Position)
		world.Players = append(world.Players, pl)
	}

	for i := 0; i < EntitiesInitSpawnNumber; i++ {
		world.SpawnEntity()
	}

	for world.Running() {
		world.Tick()

		area := (world.MaxX - world.MinX) * (world.MaxY - world.MinY)
		maxArea := float32((MaxX - MinX) * (MaxY - MinY))

		world.Runner.Log(fmt.Sprintf("prob: %f", area/maxArea*MaxEntitySpawnProb))

		if rand.Float32() < area/maxArea*MaxEntitySpawnProb && len(world.Entities) < MaxEntitiesCount {
			world.SpawnEntity()
		}
		world.Shrink()

		if world.TickNumber > IncreaseOutOfWorldKill {
			PlayerOutOfWorldHealth = BiggerPlayerOutOfWorldHealth
		}

		world.TickNumber++
	}

	// add last alive player to DiedOrder
	for _, player := range world.Players {
		if player.Alive {
			world.DiedOrder = append(world.DiedOrder, player)
		}
	}

	// add DiedOrder scores to players and create Scores
	var scores = map[string]int{}
	for i, player := range world.DiedOrder {
		player.Score += int(math.Pow(float64(i*DiedOrderConstant), DiedOrderPower))
		scores[player.Name] = player.Score
	}
	world.Runner.Scores(scores)

	err := world.SaveStats()
	if err != nil {
		world.Runner.Log(fmt.Sprintf("error while saving score: %s", err.Error()))
	}

	world.Runner.End()
}
