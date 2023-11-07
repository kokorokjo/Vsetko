package main

type MachineGunTank struct {
	//TODO constants
}

func (t MachineGunTank) Fire(player *Player, playerMovement PlayerMovement, angle2 float32, target Target) (float32, float32) {
	var bullet = NewBullet(player.World, player.Id, player.Position, player.RealStatsValues(), playerMovement, player.Angle, 5, true, nil)
	return bullet.Vx * t.KnockBack(), bullet.Vy * t.KnockBack()
}

func (t MachineGunTank) StatsValues() StatsValues {
	return StatsValues{
		Range:              300,
		Speed:              0,
		BulletSpeed:        20,
		BulletTTL:          -2,
		BulletDamage:       -4,
		HealthMax:          0,
		HealthRegeneration: 0,
		BodyDamage:         0,
		ReloadSpeed:        -5,
	}
}

func (t MachineGunTank) CoefStatsValues() StatsValues {
	return StatsValues{
		Range:              1,
		Speed:              1,
		BulletSpeed:        1,
		BulletTTL:          0.5,
		BulletDamage:       0.4,
		HealthMax:          1,
		HealthRegeneration: 1,
		BodyDamage:         1,
		ReloadSpeed:        1,
	}
}

func (t MachineGunTank) Radius() float32 {
	return 5
}

func (t MachineGunTank) TankLevel() int {
	return 0
}

func (t MachineGunTank) TankId() int {
	return 8
}

func (t MachineGunTank) UpdatableTo() []Tank {
	return nil
}

func (t MachineGunTank) KnockBack() float32 {
	return 0
}
