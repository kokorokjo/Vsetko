package main

type WideBulletTank struct {
	//TODO constants
}

func (t WideBulletTank) Fire(player *Player, playerMovement PlayerMovement, angle2 float32, target Target) (float32, float32) {
	var bullet = NewBullet(player.World, player.Id, player.Position, player.RealStatsValues(), playerMovement, player.Angle, 15, true, nil)
	return bullet.Vx * t.KnockBack(), bullet.Vy * t.KnockBack()
}

func (t WideBulletTank) StatsValues() StatsValues {
	return StatsValues{
		Range:              600,
		Speed:              0,
		BulletSpeed:        10,
		BulletTTL:          0,
		BulletDamage:       20,
		HealthMax:          50,
		HealthRegeneration: 2,
		BodyDamage:         0,
		ReloadSpeed:        6,
	}
}

func (t WideBulletTank) Radius() float32 {
	return 5
}

func (t WideBulletTank) TankLevel() int {
	return 0
}

func (t WideBulletTank) TankId() int {
	return 6
}

func (t WideBulletTank) UpdatableTo() []Tank {
	return nil
}

func (t WideBulletTank) KnockBack() float32 {
	return -0.3
}
