package main

const (
	StatNone Stat = iota
	StatRange
	StatSpeed
	StatBulletSpeed
	StatBulletTTL
	StatBulletDamage
	StatHealthMax
	StatHealthRegeneration
	StatBodyDamage
	StatReloadSpeed
)

var RangeValues = []float32{500, 600, 700, 800, 900, 1000, 1100, 1200}
var SpeedValues = []float32{5, 7, 10, 12, 15, 17, 20, 23}
var BulletSpeedValues = []float32{70, 75, 80, 85, 90, 95, 100, 105}
var BulletTTLValues = []float32{2, 4, 6, 8, 10, 12, 14, 16}
var BulletDamageValues = []float32{10, 15, 20, 25, 30, 35, 40, 45}
var HealthMaxValues = []float32{100, 130, 160, 190, 220, 250, 280, 310}
var HealthRegenerationValues = []float32{0, 0.5, 1, 1.5, 2, 2.5, 3, 3.5}
var BodyDamageValues = []float32{1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5}
var ReloadSpeedValues = []int{14, 13, 12, 11, 10, 9, 8, 7}
var LevelUpdateExp = []int{10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 133, 166, 200, 233, 266, 300, 350, 400, 450, 500, 600, 700, 800, 900, 1000, 1200, 1400, 1600, 1800, 2000}
