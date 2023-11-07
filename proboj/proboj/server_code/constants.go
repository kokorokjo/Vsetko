package main

const MinX = -4000
const MaxX = 4000
const MinY = -4000
const MaxY = 4000
const WorldSizeShrink = 5
const MinWorldSize = 2000
const SpawnIterations = 10
const TankLevelUpdateFreq = 10
const PlayerEntityCollisionHealth = 10

var PlayerOutOfWorldHealth = 15

const BiggerPlayerOutOfWorldHealth = 30
const IncreaseOutOfWorldKill = 3000
const EntityHitExpCoefficient = 0.3
const EntityCollisionExpCoefficient = 0.3
const PlayerHitExpCoefficient = 0.5
const PlayerCollisionExpCoefficient = 0.5
const BulletCollisionTTL = 5
const MaxRespawn = 3
const EntitiesInitSpawnNumber = 200
const MaxEntitySpawnProb = 0.2
const MaxEntityRadius = 30
const MinEntityRadius = 20
const MaxEntityHealth = 40
const FractionOfPlayerSpeedToBullet = 0
const ShrinkWorldAfter = 800
const KillPlayerExp = 100
const KillEntityExp = 20
const DiedOrderConstant = 5000
const DiedOrderPower = 1.5
const MaxEntitiesCount = 40000
