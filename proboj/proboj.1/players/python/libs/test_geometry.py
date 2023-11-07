import math
from unittest import TestCase

from libs.geometry import *


class TestSegment(TestCase):
    def test_collides(self):
        self.assertTrue(Segment.collides(Segment(XY(0, 0), XY(0, 0)), 1,
                                         Segment(XY(1, 0), XY(1, 0)), 1))

        self.assertFalse(Segment.collides(Segment(XY(0, 0), XY(0, 0)), 1,
                                          Segment(XY(10, 10), XY(10, 10)), 1))

        self.assertTrue(Segment.collides(Segment(XY(0, 0), XY(10, 0)), 1,
                                         Segment(XY(5, 0), XY(5, 0)), 1))

        self.assertTrue(Segment.collides(Segment(XY(0, 0), XY(1, 0)), 1,
                                         Segment(XY(1, 0), XY(0, 0)), 1))

        self.assertTrue(Segment.collides(Segment(XY(0, 0), XY(1, 0)), 0,
                                         Segment(XY(1, 0), XY(0, 0)), 0))

        self.assertTrue(Segment.collides(Segment(XY(0, 0), XY(1, 0)), 1,
                                         Segment(XY(1, 1), XY(0, 1)), 1))

        self.assertTrue(Segment.collides(Segment(XY(0, 0), XY(1, 0)), 0.5,
                                         Segment(XY(1, 1), XY(0, 1)), 0.5))

        self.assertFalse(Segment.collides(Segment(XY(0, 0), XY(1, 0)), 0.5,
                                          Segment(XY(1, 1), XY(0, 1)), 0.49))

        self.assertFalse(Segment.collides(Segment(XY(0, 0), XY(0, 100)), 1,
                                          Segment(XY(-100, 100), XY(100, 100)), 1))

        self.assertFalse(Segment.collides(Segment(XY(0, 0), XY(0, 100)), 1,
                                          Segment(XY(-100, 0), XY(100, 0)), 1))


class TestXY(TestCase):
    def test_dot(self):
        self.assertEqual(XY.dot(XY(0, 1), XY(1, 0)), 0)
        self.assertEqual(XY.dot(XY(0, 1), XY(0, 1)), 1)

    def test_squared_distance(self):
        self.assertEqual(XY.squared_distance(XY(1, 1), XY(1, 2)), 1)
        self.assertEqual(XY.squared_distance(XY(1, 1), XY(1, 3)), 4)

    def test_distance(self):
        self.assertEqual(XY.distance(XY(1, 1), XY(2, 2)), math.sqrt(2))
        self.assertEqual(XY.distance(XY(1, 1), XY(10, 1)), 9)
        self.assertEqual(XY.distance(XY(10, 1), XY(1, 1)), 9)

    def test_angle_to(self):
        self.assertEqual(XY(1, 1).angle_to(XY(2, 1)), 0)
        self.assertEqual(XY(1, 1).angle_to(XY(1, 2)), math.pi/2)
        self.assertEqual(XY(5, 5).angle_to(XY(4, 5)),
                         math.pi)
