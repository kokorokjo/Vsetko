from abc import ABC, abstractmethod
from dataclasses import dataclass
from typing import List

from libs.stats import Stats


@dataclass
class Tank(ABC):

    @staticmethod
    def get_all_tanks():
        return [
            AsymetricTripleTank(),
            DoubleDoubleTank(),
            EverywhereTank(),
            GuidedBulletTank(),
            InvisibleBulletTank(),
            MachineGunTank(),
            PeacefulTank(),
            VariableDoubleTank(),
            WideBulletTank(),
            TwinTank(),
            SniperTank(),
            AsymetricTank(),
            BasicTank()
        ]

    @staticmethod
    def get_tank(id: int):
        for tank in Tank.get_all_tanks():
            if tank.tank_id == id:
                return tank
        raise RuntimeError(f"Tank w/ {id} not found")

    @abstractmethod
    def tank_id(self) -> int:
        pass

    @abstractmethod
    def updatable_to(self) -> List:
        pass

    @abstractmethod
    def stats_values(self) -> Stats:
        pass


@dataclass
class AsymetricTripleTank(Tank):
    tank_id = 12
    updatable_to = []
    stats_values = Stats([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])


@dataclass
class DoubleDoubleTank(Tank):
    tank_id = 4
    updatable_to = []
    stats_values = Stats([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])


@dataclass
class EverywhereTank(Tank):
    tank_id = 2
    updatable_to = []
    stats_values = Stats([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])


@dataclass
class GuidedBulletTank(Tank):
    tank_id = 7
    updatable_to = []
    stats_values = Stats([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])


@dataclass
class InvisibleBulletTank(Tank):
    tank_id = 11
    updatable_to = []
    stats_values = Stats([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])


@dataclass
class MachineGunTank(Tank):
    tank_id = 8
    updatable_to = []
    stats_values = Stats([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])


@dataclass
class PeacefulTank(Tank):
    tank_id = 10
    updatable_to = []
    stats_values = Stats([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])


@dataclass
class VariableDoubleTank(Tank):
    tank_id = 3
    updatable_to = []
    stats_values = Stats([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])


@dataclass
class WideBulletTank(Tank):
    tank_id = 6
    updatable_to = []
    stats_values = Stats([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])


@dataclass
class TwinTank(Tank):
    tank_id = 1
    updatable_to = [EverywhereTank, DoubleDoubleTank, VariableDoubleTank]
    stats_values = Stats([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])


@dataclass
class SniperTank(Tank):
    tank_id = 5
    updatable_to = [WideBulletTank, GuidedBulletTank, MachineGunTank]
    stats_values = Stats([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])


@dataclass
class AsymetricTank(Tank):
    tank_id = 9
    updatable_to = [PeacefulTank, InvisibleBulletTank, AsymetricTripleTank]
    stats_values = Stats([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])


@dataclass
class BasicTank(Tank):
    tank_id = 0
    updatable_to = [TwinTank, SniperTank, AsymetricTank]
    stats_values = Stats([0, 0, 0, 0, 0, 0, 0, 0, 0, 0])
