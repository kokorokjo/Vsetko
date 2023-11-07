import enum


class StatsEnum(enum.Enum):
    StatNone = 0
    StatRange = 1
    StatSpeed = 2
    StatBulletSpeed = 3
    StatBulletTTL = 4
    StatBulletDamage = 5
    StatHealthMax = 6
    StatHealthRegeneration = 7
    StatBodyDamage = 8
    StatReloadSpeed = 9


class Stats:

    def __init__(self, stats):
        assert len(stats) == len(StatsEnum)
        self.stats = stats[:]

    @staticmethod
    def read_stat_levels():
        stats = [0]
        for idx, lvl in enumerate(map(int, input().split())):
            stats.append(lvl)
        return Stats(stats)

    @staticmethod
    def read_stat_values():
        stats = [0]
        for idx, lvl in enumerate(map(float, input().split())):
            stats.append(lvl)
        return Stats(stats)

    def __getitem__(self, key: StatsEnum):
        return self.stats[key.value]
