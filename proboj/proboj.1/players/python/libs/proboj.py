import sys
from typing import Set

from libs.geometry import XY
from libs.tanks import *
from libs.shoot import Shoot
from libs.stats import *


class Turn:
    """
    Reprezentuje ťah v hre. Hráč vracia rýchlosť, smer, ktorým sa chce pohnúť,
    či chce vystreliť, ktorý Stat chce updatnúť a id tanku, ktorý by chcel mať.
    """

    def __init__(self, velocity: XY, shoot: Shoot, stat: StatsEnum, new_tank_id: int):
        self.x = float(velocity.x)
        self.y = float(velocity.y)
        self.shoot = shoot
        self.stat = int(stat.value)
        if new_tank_id is None:
            self.new_tank_id = 0
        else:
            self.new_tank_id = int(new_tank_id)

    def print(self):
        print(f"{self.x} {self.y} {self.shoot} {self.stat} {self.new_tank_id}")
        print(".")

class Player:
    """
    Trieda, ktorá reprezentuje bežného hráča v hre.
    * idx - jeho idčko
    * alive - bool, či hráč žije. Snáď by ste ani nemali dostať nie alive hráča.
    * position - XY hráča
    * angle - uhol, kam je aktuálne natočená hlaveň
    * radius - polomer hráča
    * health - health
    """

    def __init__(self):
        self.id: int = 0
        self.alive: bool = False
        self.position: XY
        self.angle: float = 0
        self.radius: float = 0
        self.tank: Tank
        self.health: float = 0

    @classmethod
    def read_player(cls) -> "Player":
        id, alive, x, y, angle, radius, tank_id, health = input().split()
        player = Player()
        player.id = int(id)
        player.alive = bool(int(alive))
        player.position = XY(float(x), float(y))
        player.angle = float(angle)
        player.radius = float(radius)
        player.tank = Tank.get_tank(int(tank_id))
        player.health = float(health)
        return player

    def merge(self, player: "Player"):
        self.id = player.id
        self.alive = player.alive
        self.position = player.position
        self.angle = player.angle
        self.radius = player.radius
        self.tank = player.tank
        self.health = player.health

    def __eq__(self, other):
        return self.id == other.id

    def __hash__(self):
        return self.id


class MyPlayer(Player):
    """
    Trieda, ktorá reprezentuje Tvojho hráča v hre.
    * exp - získané XPčka
    * level - ktorý si záskal
    * levels_left - koľko levelov môžeš ešte použiť na vylepšovanie
    * tank_updates_left - koľko updatov tankov môžeš ešte použiť
    * reload_cooldown - koľko tickcov ešte nemôžeš strieľať
    * lifes_left - koľko respawnov ešte máš
    * stat_levels - aké sú aktuálne levely Tvojich statov
    * stat_values - aké sú aktuálne hodnoty Tvojich statov
    """

    def __init__(self):
        super().__init__()
        self.exp: int
        self.level: int
        self.levels_left: int
        self.tank_updates_left: int
        self.reload_cooldown: int
        self.lifes_left: int
        self.stat_levels: Stats
        self.stat_values: Stats

    @classmethod
    def read_myplayer(cls) -> "MyPlayer":
        id, exp, level, levels_left, tank_updates_left, reload_cooldown, lifes_left = input().split()
        myplayer = MyPlayer()
        myplayer.id = int(id)
        myplayer.exp = int(exp)
        myplayer.level = int(level)
        myplayer.levels_left = int(levels_left)
        myplayer.tank_updates_left = int(tank_updates_left)
        myplayer.reload_cooldown = int(reload_cooldown)
        myplayer.lifes_left = int(lifes_left)
        myplayer.stat_levels = Stats.read_stat_levels()
        myplayer.stat_values = Stats.read_stat_values()
        return myplayer


class ProbojPlayer:
    """
    Táto trieda vykonáva ťahy v hre
    * world - objekt, ktorý reprezentuje svet
    * myself - Ty
    * _myself - Tvoje id
    * players - `dictionary` hráčov `{id: Player}`
    * bullets - `set` projektilov
    * entities - `set` entít
    """

    def __init__(self):
        self.world: World
        self.myself: MyPlayer
        self._myself: int
        self.players: dict[int: Player]
        self.bullets: Set[Bullet]
        self.entities: Set[Entity]

    @staticmethod
    def log(*args):
        """
        Vypíše dáta do logu. Syntax je rovnaká ako print().
        """
        print(*args, file=sys.stderr)

    def _read_myself(self):
        """
        Načíta info o sebe
        """
        self.myself = MyPlayer.read_myplayer()
        self._myself = self.myself.id

    def _read_players(self):
        """
        Načíta hráčov v dosahu hráča
        """
        self.players = {}
        n = int(input())
        for i in range(n):
            player = Player.read_player()
            self.players[player.id] = player

        self.myself.merge(self.players[self._myself])

    def _read_bullets(self):
        """
        Načíta projektily v dosahu hráča
        """
        self.bullets = set()
        n = int(input())
        for i in range(n):
            bullet = Bullet.read_bullet()
            self.bullets.add(bullet)

    def _read_entities(self):
        """
        Načíta entity v dosahu hráča
        """
        self.entities = set()
        n = int(input())
        for i in range(n):
            entity = Entity.read_entity()
            self.entities.add(entity)

    def _read_turn(self):
        """
        Načíta vstup pre hráča
        """
        self.world = World.read_world()
        self._read_myself()
        self._read_players()
        self._read_bullets()
        self._read_entities()
        input()
        input()

    def _send_turns(self, turn: Turn):
        """
        Odošle ťah serveru.
        """
        turn.print()

    def make_turn(self) -> Turn:
        """
        Vykoná ťah.
        Funkcia vracia objekt Turn
        """
        raise NotImplementedError()

    def run(self):
        """
        Hlavný cyklus hry.
        """
        while True:
            self._read_turn()
            turns = self.make_turn()
            self._send_turns(turns)


@dataclass
class Bullet:
    """
    Projektil:
    * position - `XY`, pozícia
    * velocity - `XY`, rýchlosť
    * shooter_id - id strelca, kľúč do poľa hráčov
    * ttl - koľko tickov ešte projektil bude existovať
    * damage - koľko damage spôsobí pri hite
    """
    position: XY
    velocity: XY
    shooter_id: int
    ttl: float
    damage: float
    radius: float

    @classmethod
    def read_bullet(cls) -> "Bullet":
        x, y, vx, vy, shooter_id, ttl, damage, radius = input().split()
        return Bullet(
            XY(float(x), float(y)),
            XY(float(vx), float(vy)),
            int(shooter_id),
            float(ttl),
            float(damage),
            float(radius),
        )

    def __hash__(self):
        return hash((self.position, self.velocity))


@dataclass
class Entity:
    """
    Entita:
    * position - `XY`, pozícia
    * radius - polomer
    """
    position: XY
    radius: float
    health: float

    @classmethod
    def read_entity(cls) -> "Entity":
        x, y, radius, health = input().split()
        return Entity(XY(float(x), float(y)), float(radius), float(health))

    def __hash__(self):
        return hash((self.position, self.radius))


@dataclass
class World:
    """
    World:
    * size - veľkosť mapy, v oboch rozmeroch je to od `+size` do `-size`
    """

    min_x: float
    max_x: float
    min_y: float
    max_y: float

    @classmethod
    def read_world(cla) -> "World":
        return World(*map(float, input().split()))
