package main

type InvisibleBulletTank struct {
	//TODO constants
}

func (t InvisibleBulletTank) Fire(player *Player, playerMovement PlayerMovement, angle2 float32, target Target) (float32, float32) {
	var bullet = NewBullet(player.World, player.Id, player.Position, player.RealStatsValues(), playerMovement, player.Angle, 20, false, nil)
	return bullet.Vx * t.KnockBack(), bullet.Vy * t.KnockBack()
}

func (t InvisibleBulletTank) StatsValues() StatsValues {
	return StatsValues{
		Range:              300,
		Speed:              -2,
		BulletSpeed:        0,
		BulletTTL:          -3,
		BulletDamage:       -3,
		HealthMax:          0,
		HealthRegeneration: 0,
		BodyDamage:         0,
		ReloadSpeed:        2,
	}
}

func (t InvisibleBulletTank) CoefStatsValues() StatsValues {
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

func (t InvisibleBulletTank) Radius() float32 {
	return 5
}

func (t InvisibleBulletTank) TankLevel() int {
	return 0
}

func (t InvisibleBulletTank) TankId() int {
	return 11
}

func (t InvisibleBulletTank) UpdatableTo() []Tank {
	return nil
}

func (t InvisibleBulletTank) KnockBack() float32 {
	return -0.1
}
