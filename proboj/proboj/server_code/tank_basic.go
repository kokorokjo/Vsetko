package main

type BasicTank struct {
	//TODO constants
}

func (t BasicTank) Fire(player *Player, playerMovement PlayerMovement, angle2 float32, target Target) (float32, float32) {
	var bullet = NewBullet(player.World, player.Id, player.Position, player.RealStatsValues(), playerMovement, player.Angle, 5, true, nil)
	return bullet.Vx * t.KnockBack(), bullet.Vy * t.KnockBack()
}

func (t BasicTank) StatsValues() StatsValues {
	return StatsValues{
		Range:              0,
		Speed:              0,
		BulletSpeed:        0,
		BulletTTL:          0,
		BulletDamage:       0,
		HealthMax:          0,
		HealthRegeneration: 0,
		BodyDamage:         0,
		ReloadSpeed:        0,
	}
}

func (t BasicTank) Radius() float32 {
	return 5
}

func (t BasicTank) TankLevel() int {
	return 0
}

func (t BasicTank) TankId() int {
	return 0
}

func (t BasicTank) UpdatableTo() []Tank {
	return []Tank{TwinTank{}, SniperTank{}, AsymetricTank{}}
}

func (t BasicTank) KnockBack() float32 {
	return -0.1
}
