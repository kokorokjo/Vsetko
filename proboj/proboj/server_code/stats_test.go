package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestStat_IsValid(t *testing.T) {
	assert.True(t, Stat(0).IsValid())
	assert.True(t, Stat(9).IsValid())
	assert.False(t, Stat(-1).IsValid())
	assert.False(t, Stat(173).IsValid())
}

func TestPlayer_UpgradeStat_Errors(t *testing.T) {
	p := Player{}
	assert.Error(t, p.UpgradeStat(2345))
	assert.Error(t, p.UpgradeStat(StatNone))
	assert.Error(t, p.UpgradeStat(StatBulletDamage))
}

func TestPlayer_UpgradeStat(t *testing.T) {
	var p Player
	cases := []struct {
		stat      Stat
		result    *int
		maxLevels int
	}{
		{StatRange, &p.Stats.Range, len(RangeValues)},
		{StatSpeed, &p.Stats.Speed, len(SpeedValues)},
		{StatBulletSpeed, &p.Stats.BulletSpeed, len(BulletSpeedValues)},
		{StatBulletTTL, &p.Stats.BulletTTL, len(BulletTTLValues)},
		{StatBulletDamage, &p.Stats.BulletDamage, len(BulletDamageValues)},
		{StatHealthMax, &p.Stats.HealthMax, len(HealthMaxValues)},
		{StatHealthRegeneration, &p.Stats.HealthRegeneration, len(HealthRegenerationValues)},
		{StatBodyDamage, &p.Stats.BodyDamage, len(BodyDamageValues)},
		{StatReloadSpeed, &p.Stats.ReloadSpeed, len(ReloadSpeedValues)},
	}

	for _, test := range cases {
		// normal upgrade
		p.LevelsLeft = 1
		assert.Nil(t, p.UpgradeStat(test.stat))
		assert.Equal(t, *test.result, 1)
		assert.Equal(t, p.LevelsLeft, 0)

		// upgrade over limit
		p.LevelsLeft = 1
		*test.result = test.maxLevels - 1
		assert.Error(t, p.UpgradeStat(test.stat))
		assert.Equal(t, *test.result, test.maxLevels-1)
		assert.Equal(t, p.LevelsLeft, 1)
	}
}
