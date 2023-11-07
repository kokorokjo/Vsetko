package main

type VariableDoubleTank struct {
	//TODO constants
}

func (t VariableDoubleTank) Fire(player *Player, playerMovement PlayerMovement, angle2 float32, target Target) (float32, float32) {
	var bullet1 = NewBullet(player.World, player.Id, player.Position, player.RealStatsValues(), playerMovement, player.Angle, 5, true, nil)
	var bullet2 = NewBullet(player.World, player.Id, player.Position, player.RealStatsValues(), playerMovement, angle2, 5, true, nil)
	return (bullet1.Vx + bullet2.Vx) * t.KnockBack(), (bullet1.Vy + bullet2.Vy) * t.KnockBack()
}

func (t VariableDoubleTank) StatsValues() StatsValues {
	return StatsValues{
		Range:              300,
		Speed:              0,
		BulletSpeed:        0,
		BulletTTL:          -1,
		BulletDamage:       -2,
		HealthMax:          0,
		HealthRegeneration: 0,
		BodyDamage:         0,
		ReloadSpeed:        0,
	}
}

func (t VariableDoubleTank) Radius() float32 {
	return 5
}

func (t VariableDoubleTank) TankLevel() int {
	return 1
}

func (t VariableDoubleTank) TankId() int {
	return 3
}

func (t VariableDoubleTank) UpdatableTo() []Tank {
	return nil
}

func (t VariableDoubleTank) KnockBack() float32 {
	return -0.1
}
