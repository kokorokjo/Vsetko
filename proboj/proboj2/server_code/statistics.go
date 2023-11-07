package main

import (
	"encoding/json"
	"os"
)

type Statistics struct {
	TimeByTank        map[int]int    `json:"time_by_tank"`
	ScoreByReason     map[Reason]int `json:"score_by_reason"`
	TimeInCooldown    int            `json:"time_in_cooldown"`
	TimeNotInCooldown int            `json:"time_not_in_cooldown"`
	TimeOfResponses   int64          `json:"time_of_responses"`
}

type Reason int

const (
	BodyDamagePlayer Reason = iota
	BulletDamagePlayer
	BodyDamageEntity
	BulletDamageEntity
	KillPlayer
	KillEntity
)

func (w *World) SaveStats() error {
	stats := map[string]Statistics{}
	for _, player := range w.Players {
		stats[player.Name] = player.Statistics
	}

	f, err := os.Create("stats.json")
	if err != nil {
		return err
	}
	defer f.Close()

	data, err := json.Marshal(stats)
	if err != nil {
		return err
	}

	_, err = f.Write(data)
	return err
}
