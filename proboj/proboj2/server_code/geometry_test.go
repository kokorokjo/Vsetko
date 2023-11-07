package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestCollides(t *testing.T) {
	assert.True(t, Collides(Segment{Position{X: 0, Y: 0}, Position{X: 0, Y: 0}}, 1,
		Segment{Position{X: 1, Y: 0}, Position{X: 1, Y: 0}}, 1))

	assert.False(t, Collides(Segment{Position{X: 0, Y: 0}, Position{X: 0, Y: 0}}, 1,
		Segment{Position{X: 10, Y: 10}, Position{X: 10, Y: 10}}, 1))

	assert.True(t, Collides(Segment{Position{X: 0, Y: 0}, Position{X: 10, Y: 0}}, 1,
		Segment{Position{X: 5, Y: 0}, Position{X: 5, Y: 0}}, 1))

	assert.True(t, Collides(Segment{Position{X: 0, Y: 0}, Position{X: 1, Y: 0}}, 1,
		Segment{Position{X: 1, Y: 0}, Position{X: 0, Y: 0}}, 1))

	assert.True(t, Collides(Segment{Position{X: 0, Y: 0}, Position{X: 1, Y: 0}}, 0,
		Segment{Position{X: 1, Y: 0}, Position{X: 0, Y: 0}}, 0))

	assert.True(t, Collides(Segment{Position{X: 0, Y: 0}, Position{X: 1, Y: 0}}, 1,
		Segment{Position{X: 1, Y: 1}, Position{X: 0, Y: 1}}, 1))

	assert.True(t, Collides(Segment{Position{X: 0, Y: 0}, Position{X: 1, Y: 0}}, 0.5,
		Segment{Position{X: 1, Y: 1}, Position{X: 0, Y: 1}}, 0.5))

	assert.False(t, Collides(Segment{Position{X: 0, Y: 0}, Position{X: 1, Y: 0}}, 0.5,
		Segment{Position{X: 1, Y: 1}, Position{X: 0, Y: 1}}, 0.49))

	assert.False(t, Collides(Segment{Position{X: 0, Y: 0}, Position{X: 0, Y: 100}}, 1,
		Segment{Position{X: -100, Y: 100}, Position{X: 100, Y: 100}}, 1))

	assert.False(t, Collides(Segment{Position{X: 0, Y: 0}, Position{X: 0, Y: 100}}, 1,
		Segment{Position{X: -100, Y: 0}, Position{X: 100, Y: 0}}, 1))
}
