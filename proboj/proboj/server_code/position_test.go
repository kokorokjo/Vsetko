package main

import "testing"
import "github.com/stretchr/testify/assert"

func TestPosition_SquaredDistance(t *testing.T) {
	p1 := Position{
		X: 10.4,
		Y: 23.2,
	}
	p2 := Position{
		X: -2.1,
		Y: 6.4,
	}
	assert.InDelta(t, p1.SquaredDistance(p2), 438.49, 1e-4)
}

func TestPosition_Distance(t *testing.T) {
	p1 := Position{
		X: 10.4,
		Y: 23.2,
	}
	p2 := Position{
		X: -2.1,
		Y: 6.4,
	}
	assert.InDelta(t, p1.Distance(p2), 20.940152817016404, 1e-4)
}

func TestPosition_Reachable(t *testing.T) {
	p1 := Position{
		X: 10.4,
		Y: 23.2,
	}
	p2 := Position{
		X: -2.1,
		Y: 6.4,
	}
	assert.True(t, p1.Reachable(p2, 200))
	assert.True(t, p1.Reachable(p2, 20.9402))
	assert.False(t, p1.Reachable(p2, 20.9400))
	assert.False(t, p1.Reachable(p2, 2))
}
