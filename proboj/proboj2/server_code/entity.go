package main

import "math/rand"

type Entity struct {
	Position `json:"position"`
	Radius   float32 `json:"radius"`
	Health   float32 `json:"health"`
}

func (e *Entity) SetHealth(health float32) {
	e.Health = health
	e.Radius = MinEntityRadius + e.Health/MaxEntityHealth*(MaxEntityRadius-MinEntityRadius)
}

func (w *World) NewEntity() Entity {
	var entity = Entity{}
	entity.SetHealth(rand.Float32() * MaxEntityHealth)
	return entity
}
