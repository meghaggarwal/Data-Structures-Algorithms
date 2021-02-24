from cuboid_vol import *
import unittest

class TestCuboid(unittest.TestCase):
  def test_volume(self):
    self.assertAlmostEqual(cuboid_volume(2), 8)
    self.assertAlmostEqual(cuboid_volume(7), 343)
    self.assertEqual(cuboid_volume(4), 64)


  def test_input_values(self):
    self.assertRaises(TypeError, cuboid_volume, True)