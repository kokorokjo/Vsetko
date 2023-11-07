from libs.geometry import XY


class Shoot:
    """
    Nadrieda, ktorá reprezentuje výstrel.
    """


class XyShoot(Shoot):

    def __init__(self, xy: XY):
        self.xy = xy

    def __str__(self):
        return f"4 {self.xy.x} {self.xy.y}"


class NoShoot(Shoot):
    def __str__(self):
        return "0"


class OneBulletShoot(Shoot):
    def __init__(self, angle: float):
        self.angle = angle

    def __str__(self):
        return f"1 {self.angle}"


class TwoBulletShoot(Shoot):
    def __init__(self, angle1: float, angle2: float):
        self.angle1 = angle1
        self.angle2 = angle2

    def __str__(self):
        return f"2 {self.angle1} {self.angle2}"


class PlayerShoot(Shoot):
    def __init__(self, player_id: int):
        self.player_id = player_id

    def __str__(self):
        return f"3 {self.player_id}"