package main

type Segment struct {
	A Position
	B Position
}

// Length returns the length of the segment
func (s Segment) Length() float32 {
	return s.A.Distance(s.B)
}

// SquaredLength returns the squared length of the segment
func (s Segment) SquaredLength() float32 {
	return s.A.SquaredDistance(s.B)
}

// Collides checks whether two segments with given radiuses intersects
func Collides(s1 Segment, r1 float32, s2 Segment, r2 float32) bool {
	s2.B.X -= s1.B.X - s1.A.X
	s2.B.Y -= s1.B.Y - s1.A.Y
	return segmentPointDistance(s2, s1.A) <= r1+r2
}

// segmentPointDistance returns distance between a Segment and a Position.
// https://stackoverflow.com/a/1501725
func segmentPointDistance(segment Segment, point Position) float32 {
	length := segment.SquaredLength()

	// The segment's length is zero.
	if length <= 1e-9 && length >= -1e-9 {
		return point.Distance(segment.A)
	}

	t := InRange(DotProduct(point, segment.A, segment.B)/length, 0, 1)
	projectionX := segment.A.X + t*(segment.B.X-segment.A.X)
	projectionY := segment.A.Y + t*(segment.B.Y-segment.A.Y)
	return point.Distance(Position{projectionX, projectionY})
}

func DotProduct(A Position, B Position, C Position) float32 {
	var AB = Position{
		X: A.X - B.X,
		Y: A.Y - B.Y,
	}
	var CB = Position{
		X: C.X - B.X,
		Y: C.Y - B.Y,
	}
	return AB.X*CB.X + AB.Y*CB.Y
}
