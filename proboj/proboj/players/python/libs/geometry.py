import math


class XY:
    """
    Trieda, ktorá reprezentuje bod/vektor v 2D.
    Mohla by mať rozuné metódy ako skalárny súčín, sčítavanie vektorov a násobenie skalárom.
    """

    def __init__(self, x: float = 0, y: float = 0):
        self.x: float = x
        self.y: float = y

    @staticmethod
    def dot(v, u):
        return v.x * u.x + v.y * u.y

    def __sub__(self, other: "XY"):
        return XY(self.x - other.x, self.y - other.y)

    def __add__(self, other: "XY"):
        return XY(self.x + other.x, self.y + other.y)

    def __imul__(self, other):
        if isinstance(other, int) or isinstance(other, float):
            return XY(self.x * other, self.y * other)
        raise ArithmeticError(f"Cannot multiply by {type(other)}")

    @staticmethod
    def squared_distance(A: "XY", B: "XY"):
        d = A - B
        return d.x * d.x + d.y * d.y

    def distance(self, other: "XY"):
        return math.sqrt(XY.squared_distance(self, other))

    def __hash__(self):
        return hash((self.x, self.y))

    def __str__(self):
        return f"({self.x} {self.y})"

    def angle_to(self, other: "XY"):
        v = other - self
        return math.atan2(v.y, v.x)


class Segment:
    """
        Trieda, ktorá reprezentuje úsečku v 2D.
        Používame ju najmä na zisťovanie, či sa dve entity pretínajú (pri pohybe).
    """

    def __init__(self, A, B):
        self.A = A
        self.B = B

    @staticmethod
    def collides(s1: "Segment", r1: float, s2: "Segment", r2: float) -> bool:
        s2.B.x -= s1.B.x - s1.A.x
        s2.B.y -= s1.B.y - s1.A.y
        return Segment.segment_point_distance(s2, s1.A) <= r1 + r2

    @staticmethod
    def segment_point_distance(segment: "Segment", point: "XY") -> float:
        """
        segmentPointDistance returns distance between a Segment and a Position.
        https://stackoverflow.com/a/1501725
        """

        length = XY.squared_distance(segment.A, segment.B)

        # The segment's length is zero.
        if 1e-9 >= length >= -1e-9:
            return point.distance(segment.A)

        t = min(1, max(0, (XY.dot(point - segment.A, segment.B - segment.A) / length)))
        projection_x = segment.A.x + t * (segment.B.x - segment.A.x)
        projection_y = segment.A.y + t * (segment.B.y - segment.A.y)
        return point.distance(XY(projection_x, projection_y))
