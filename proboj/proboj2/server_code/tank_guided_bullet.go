package main

import "fmt"

type GuidedBulletTank struct {
	//TODO constants
}

func (t GuidedBulletTank) Fire(player *Player, playerMovement PlayerMovement, angle2 float32, target Target) (float32, float32) {
	if target == nil {
		player.World.Runner.Log(fmt.Sprintf("(%s) guided bullet fire without appropriate target (ignoring)", player.Name))
		return 0, 0
	}
	var bullet = NewBullet(player.World, player.Id, player.Position, player.RealStatsValues(), playerMovement, target.Angle(player.Position, player.Angle), 5, true, target)
	return bullet.Vx * t.KnockBack(), bullet.Vy * t.KnockBack()
}

func (t GuidedBulletTank) StatsValues() StatsValues {
	return StatsValues{
		Range:              800,
		Speed:              0,
		BulletSpeed:        0,
		BulletTTL:          8,
		BulletDamage:       10,
		HealthMax:          0,
		HealthRegeneration: 0,
		BodyDamage:         0,
		ReloadSpeed:        10,
	}
}

func (t GuidedBulletTank) CoefStatsValues() StatsValues {
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

func (t GuidedBulletTank) Radius() float32 {
	return 5
}

func (t GuidedBulletTank) TankLevel() int {
	return 0
}

func (t GuidedBulletTank) TankId() int {
	return 7
}

func (t GuidedBulletTank) UpdatableTo() []Tank {
	return nil
}

func (t GuidedBulletTank) KnockBack() float32 {
	return -0.2
}
