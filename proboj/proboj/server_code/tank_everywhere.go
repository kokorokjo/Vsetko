package main

import "math"

type EverywhereTank struct {
	//TODO constants
}

func (t EverywhereTank) Fire(player *Player, playerMovement PlayerMovement, angle2 float32, target Target) (float32, float32) {
	var radius float32 = 5
	var bullets = 8
	for i := 0; i < bullets; i++ {
		NewBullet(player.World, player.Id, player.Position, player.RealStatsValues(), playerMovement, player.Angle+float32(i)*2*math.Pi/float32(bullets), radius, true, nil)
	}
	return 0, 0
}

func (t EverywhereTank) StatsValues() StatsValues {
	return StatsValues{
		Range:              300,
		Speed:              0,
		BulletSpeed:        0,
		BulletTTL:          -1,
		BulletDamage:       -4,
		HealthMax:          0,
		HealthRegeneration: 0,
		BodyDamage:         0,
		ReloadSpeed:        0,
	}
}

func (t EverywhereTank) Radius() float32 {
	return 5
}

func (t EverywhereTank) TankLevel() int {
	return 1
}

func (t EverywhereTank) TankId() int {
	return 2
}

func (t EverywhereTank) UpdatableTo() []Tank {
	return nil
}

func (t EverywhereTank) KnockBack() float32 {
	return 0
}
