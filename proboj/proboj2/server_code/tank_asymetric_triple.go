package main

import "math"

type AsymetricTripleTank struct {
	//TODO constants
}

func (t AsymetricTripleTank) Fire(player *Player, playerMovement PlayerMovement, angle2 float32, target Target) (float32, float32) {
	var bullet1 = NewBullet(player.World, player.Id, player.Position, player.RealStatsValues(), playerMovement, player.Angle, 5, true, nil)
	var bullet2 = NewBullet(player.World, player.Id, player.Position, player.RealStatsValues(), playerMovement, player.Angle+2*math.Pi/3, 5, true, nil)
	var bullet3 = NewBullet(player.World, player.Id, player.Position, player.RealStatsValues(), playerMovement, player.Angle-2*math.Pi/3, 5, true, nil)
	return (bullet1.Vx + bullet2.Vx + bullet3.Vx) * t.KnockBack(), (bullet1.Vy + bullet2.Vy + bullet3.Vy) * t.KnockBack()
}

func (t AsymetricTripleTank) StatsValues() StatsValues {
	return StatsValues{
		Range:              300,
		Speed:              5,
		BulletSpeed:        0,
		BulletTTL:          0,
		BulletDamage:       0,
		HealthMax:          0,
		HealthRegeneration: 0,
		BodyDamage:         0,
		ReloadSpeed:        0,
	}
}

func (t AsymetricTripleTank) CoefStatsValues() StatsValues {
	return StatsValues{
		Range:              1,
		Speed:              1,
		BulletSpeed:        1,
		BulletTTL:          1,
		BulletDamage:       1,
		HealthMax:          1,
		HealthRegeneration: 1,
		BodyDamage:         1,
		ReloadSpeed:        1,
	}
}

func (t AsymetricTripleTank) Radius() float32 {
	return 5
}

func (t AsymetricTripleTank) TankLevel() int {
	return 0
}

func (t AsymetricTripleTank) TankId() int {
	return 12
}

func (t AsymetricTripleTank) UpdatableTo() []Tank {
	return nil
}

func (t AsymetricTripleTank) KnockBack() float32 {
	return 0.05
}
