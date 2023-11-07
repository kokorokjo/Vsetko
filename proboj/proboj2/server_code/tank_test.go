package main

import (
	"sort"
	"testing"
)
import "github.com/stretchr/testify/assert"

func TestTankIdsUnique(t *testing.T) {
	var ids []int = nil
	ids = append(ids, AsymetricTank{}.TankId())
	ids = append(ids, AsymetricTripleTank{}.TankId())
	ids = append(ids, BasicTank{}.TankId())
	ids = append(ids, DoubleDoubleTank{}.TankId())
	ids = append(ids, EverywhereTank{}.TankId())
	ids = append(ids, GuidedBulletTank{}.TankId())
	ids = append(ids, InvisibleBulletTank{}.TankId())
	ids = append(ids, MachineGunTank{}.TankId())
	ids = append(ids, PeacefulTank{}.TankId())
	ids = append(ids, SniperTank{}.TankId())
	ids = append(ids, TwinTank{}.TankId())
	ids = append(ids, VariableDoubleTank{}.TankId())
	ids = append(ids, WideBulletTank{}.TankId())
	sort.Ints(ids)
	for i := 0; i < len(ids)-1; i++ {
		assert.False(t, ids[i] == ids[i+1])
	}
	assert.Equal(t, len(ids), 13)
}

func TestTank_UpdatableTo(t *testing.T) {
	var tank Tank = BasicTank{}
	assert.Equal(t, len(tank.UpdatableTo()), 3)
	tank = TwinTank{}
	assert.Equal(t, len(tank.UpdatableTo()), 3)
	tank = SniperTank{}
	assert.Equal(t, len(tank.UpdatableTo()), 3)
	tank = AsymetricTank{}
	assert.Equal(t, len(tank.UpdatableTo()), 3)

	for _, tank := range []Tank{
		AsymetricTripleTank{},
		DoubleDoubleTank{},
		EverywhereTank{},
		GuidedBulletTank{},
		InvisibleBulletTank{},
		MachineGunTank{},
		PeacefulTank{},
		VariableDoubleTank{},
		WideBulletTank{}} {
		assert.Equal(t, len(tank.UpdatableTo()), 0)
	}
}
