package main

// InRange returns number x that is between <min, max>
// or returns the endpoints if x is out of range
func InRange(x, min, max float32) float32 {
	if x > max {
		return max
	}
	if x < min {
		return min
	}
	return x
}

func Min(a, b float32) float32 {
	if a < b {
		return a
	}
	return b
}

func Max(a, b float32) float32 {
	if a > b {
		return a
	}
	return b
}
