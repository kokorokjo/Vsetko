package main

import "math"

type Tank interface {
	Fire(player *Player, playerMovement PlayerMovement, angle2 float32, target Target) (float32, float32)
	StatsValues() StatsValues
	CoefStatsValues() StatsValues
	Radius() float32
	TankLevel() int // TODO delete?
	TankId() int
	UpdatableTo() []Tank
	KnockBack() float32
}

func CanUpdateTank(t Tank, newTankId int) (bool, Tank) {
	for _, tank := range t.UpdatableTo() {
		if tank.TankId() == newTankId {
			return true, tank
		}
	}
	return false, nil
}

func TwinShot(player *Player, playerMovement PlayerMovement, knockBack float32, angle float32) (float32, float32) {
	var radius float32 = 5

	var position1 = Position{
		X: player.Position.X + radius*float32(math.Cos(float64(angle+math.Pi/2))),
		Y: player.Position.Y + radius*float32(math.Sin(float64(angle+math.Pi/2))),
	}
	var bullet1 = NewBullet(player.World, player.Id, position1, player.RealStatsValues(), playerMovement, angle, radius, true, nil)

	var position2 = Position{
		X: player.Position.X + radius*float32(math.Cos(float64(angle-math.Pi/2))),
		Y: player.Position.Y + radius*float32(math.Sin(float64(angle-math.Pi/2))),
	}
	var bullet2 = NewBullet(player.World, player.Id, position2, player.RealStatsValues(), playerMovement, angle, radius, true, nil)
	return (bullet1.Vx + bullet2.Vx) * knockBack, (bullet1.Vy + bullet2.Vy) * knockBack
}
