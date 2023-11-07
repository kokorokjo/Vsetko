package main

import "math"

type DoubleDoubleTank struct {
	//TODO constants
}

func (t DoubleDoubleTank) Fire(player *Player, playerMovement PlayerMovement, angle2 float32, target Target) (float32, float32) {
	TwinShot(player, playerMovement, t.KnockBack(), player.Angle)
	TwinShot(player, playerMovement, t.KnockBack(), player.Angle+math.Pi)
	return 0, 0
}

func (t DoubleDoubleTank) StatsValues() StatsValues {
	return StatsValues{
		Range:              300,
		Speed:              5,
		BulletSpeed:        0,
		BulletTTL:          -1,
		BulletDamage:       -6,
		HealthMax:          0,
		HealthRegeneration: 0,
		BodyDamage:         0,
		ReloadSpeed:        0,
	}
}

func (t DoubleDoubleTank) CoefStatsValues() StatsValues {
	return StatsValues{
		Range:              1,
		Speed:              1,
		BulletSpeed:        1,
		BulletTTL:          1,
		BulletDamage:       0.7,
		HealthMax:          1,
		HealthRegeneration: 1,
		BodyDamage:         1,
		ReloadSpeed:        1,
	}
}

func (t DoubleDoubleTank) Radius() float32 {
	return 5
}

func (t DoubleDoubleTank) TankLevel() int {
	return 1
}

func (t DoubleDoubleTank) TankId() int {
	return 4
}

func (t DoubleDoubleTank) UpdatableTo() []Tank {
	return nil
}

func (t DoubleDoubleTank) KnockBack() float32 {
	return -1
}
