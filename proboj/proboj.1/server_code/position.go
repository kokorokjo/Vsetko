package main

import "math"

type Position struct {
	X float32 `json:"x"`
	Y float32 `json:"y"`
}

// SquaredDistance calculates the squared distance between two Position points
func (p Position) SquaredDistance(p2 Position) float32 {
	var dx = p.X - p2.X
	var dy = p.Y - p2.Y
	return dx*dx + dy*dy
}

// Distance calculates the euclidean distance between two Position points
func (p Position) Distance(p2 Position) float32 {
	return float32(math.Sqrt(float64(p.SquaredDistance(p2))))
}

// Reachable returns whether a distance between `p` and `p2` is less than `distance`
func (p Position) Reachable(p2 Position, distance float32) bool {
	return p.SquaredDistance(p2) < distance*distance
}
