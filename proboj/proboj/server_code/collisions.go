package main

import "fmt"

// collisionsPlayerEntity checks for collisions between players and entities
func collisionsPlayerEntity(w *World) {
	for _, playerMovement := range w.PlayerMovements {
		playerSegment := Segment{playerMovement.NewPosition, playerMovement.Player.Position}

		for j, entity := range w.Entities {
			entitySegment := Segment{entity.Position, entity.Position}
			if !Collides(playerSegment, playerMovement.Player.Tank.Radius(), entitySegment, entity.Radius) {
				continue
			}

			w.Runner.Log(fmt.Sprintf("collision: player (%s) - entity (%f, %f)", playerMovement.Player.Name, entity.X, entity.Y))
			w.Players[playerMovement.Player.Id].AddExp(int(playerMovement.Player.RealStatsValues().BodyDamage*EntityCollisionExpCoefficient), BodyDamageEntity)
			playerMovement.Player.Health -= PlayerEntityCollisionHealth

			w.Entities[j].SetHealth(w.Entities[j].Health - playerMovement.Player.RealStatsValues().BodyDamage)
			if w.Entities[j].Health < 0 {
				w.Players[playerMovement.Player.Id].AddExp(KillEntityExp, KillEntity)
			}
		}
	}
}

// collisionsPlayerPlayer checks for collisions between multiple players
func collisionsPlayerPlayer(w *World) {
	for _, playerMovement := range w.PlayerMovements {
		playerSegment := Segment{playerMovement.NewPosition, playerMovement.Player.Position}

		for _, playerMovement2 := range w.PlayerMovements {
			if playerMovement.Player == playerMovement2.Player {
				continue
			}

			playerSegment2 := Segment{playerMovement2.NewPosition, playerMovement2.Player.Position}
			if !Collides(playerSegment, playerMovement.Player.Tank.Radius(), playerSegment2, playerMovement2.Player.Tank.Radius()) {
				continue
			}

			w.Runner.Log(fmt.Sprintf("collision: player (%s) - player (%s)", playerMovement.Player.Name, playerMovement2.Player.Name))
			w.Players[playerMovement2.Player.Id].AddExp(int(playerMovement.Player.RealStatsValues().BodyDamage*PlayerCollisionExpCoefficient), BodyDamagePlayer)
			playerMovement.Player.Health -= playerMovement2.Player.RealStatsValues().BodyDamage

			if playerMovement.Player.Health < 0 {
				w.Players[playerMovement2.Player.Id].AddExp(KillPlayerExp, KillPlayer)
			}
		}
	}
}

// collisionsPlayerBullet checks for collisions between players and bullets
func collisionsPlayerBullet(w *World) {
	for _, playerMovement := range w.PlayerMovements {
		playerSegment := Segment{playerMovement.NewPosition, playerMovement.Player.Position}

		for _, bulletMovement := range w.BulletMovements {
			if bulletMovement.Bullet.ShooterId == playerMovement.Player.Id {
				continue
			}

			bulletSegment := Segment{bulletMovement.OldPosition, bulletMovement.Bullet.Position}
			if !Collides(playerSegment, playerMovement.Player.Tank.Radius(), bulletSegment, bulletMovement.Bullet.Radius) {
				continue
			}

			w.Runner.Log(fmt.Sprintf("collision: player (%s) - bullet (%f, %f)", playerMovement.Player.Name, bulletMovement.Bullet.X, bulletMovement.Bullet.Y))
			w.Players[bulletMovement.Bullet.ShooterId].AddExp(int(bulletMovement.Bullet.Damage*PlayerHitExpCoefficient), BulletDamagePlayer)

			bulletMovement.Bullet.TTL -= BulletCollisionTTL
			playerMovement.Player.Health -= bulletMovement.Bullet.Damage
			if playerMovement.Player.Health < 0 {
				w.Players[bulletMovement.Bullet.ShooterId].AddExp(KillPlayerExp, KillPlayer)
			}
		}
	}
}

// collisionsEntityBullet checks for collisions between entities and bullets
func collisionsEntityBullet(w *World) {
	for _, bulletMovement := range w.BulletMovements {
		bulletSegment := Segment{bulletMovement.OldPosition, bulletMovement.Bullet.Position}
		for e, entity := range w.Entities {
			entitySegment := Segment{entity.Position, entity.Position}
			if !Collides(bulletSegment, bulletMovement.Bullet.Radius, entitySegment, entity.Radius) {
				continue
			}

			w.Runner.Log(fmt.Sprintf("collision: bullet (%f, %f) - entity (%f, %f)", bulletMovement.Bullet.X, bulletMovement.Bullet.Y, entity.X, entity.Y))
			w.Players[bulletMovement.Bullet.ShooterId].AddExp(int(bulletMovement.Bullet.Damage*EntityHitExpCoefficient), BulletDamageEntity)

			bulletMovement.Bullet.TTL -= BulletCollisionTTL
			w.Entities[e].SetHealth(w.Entities[e].Health - bulletMovement.Bullet.Damage)
			if w.Entities[e].Health < 0 {
				w.Players[bulletMovement.Bullet.ShooterId].AddExp(KillEntityExp, KillEntity)
			}
		}
	}
}
