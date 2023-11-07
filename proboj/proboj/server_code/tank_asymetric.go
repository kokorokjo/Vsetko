package main

import "math"

type AsymetricTank struct {
	//TODO constants
}

func (t AsymetricTank) Fire(player *Player, playerMovement PlayerMovement, angle2 float32, target Target) (float32, float32) {
	var bullet1 = NewBullet(player.World, player.Id, player.Position, player.RealStatsValues(), playerMovement, player.Angle, 5, true, nil)
	var bullet2 = NewBullet(player.World, player.Id, player.Position, player.RealStatsValues(), playerMovement, player.Angle+math.Pi, 5, true, nil)
	return (bullet1.Vx + bullet2.Vx) * t.KnockBack(), (bullet1.Vy + bullet2.Vy) * t.KnockBack()
}

func (t AsymetricTank) StatsValues() StatsValues {
	return StatsValues{
		Range:              100,
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

func (t AsymetricTank) Radius() float32 {
	return 5
}

func (t AsymetricTank) TankLevel() int {
	return 0
}

func (t AsymetricTank) TankId() int {
	return 9
}

func (t AsymetricTank) UpdatableTo() []Tank {
	return []Tank{PeacefulTank{}, InvisibleBulletTank{}, AsymetricTripleTank{}}
}

func (t AsymetricTank) KnockBack() float32 {
	return 0
}
