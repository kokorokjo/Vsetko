package main

import (
	"fmt"
	"math"
)

type Target interface {
	Angle(position Position, lastAngle float32) float32
}

type PositionTarget struct {
	TargetPosition Position
}

func (p PositionTarget) Angle(position Position, lastAngle float32) float32 {
	return float32(math.Atan2(float64(p.TargetPosition.Y-position.Y), float64(p.TargetPosition.X-position.X)))
}

type PlayerTarget struct {
	Player *Player
}

func (p PlayerTarget) Angle(position Position, lastAngle float32) float32 {
	if !p.Player.Alive {
		p.Player.World.Runner.Log(fmt.Sprintf("Targeted player is not Alive. Proceeding according last direction (%f)", lastAngle))
		return lastAngle
	}
	return float32(math.Atan2(float64(p.Player.Y-position.Y), float64(p.Player.X-position.X)))
}
