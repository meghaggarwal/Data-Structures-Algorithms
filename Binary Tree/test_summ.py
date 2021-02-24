import unittest

def mul(a,b):
  return a * b

class Sum(unittest.TestCase):

  def test_sum(self):
      # assert sum([1,1]) == 8
      self.assertEqual(sum([1, 2, 3]), 6)
      self.assertEqual(mul(2,3),76)
      self.assertEqual(mul(4,5),0)

  def test_sum_tuple(self):
      self.assertEqual(sum((1, 2, 2)) , 5)
      self.assertEqual(sum((1,1)), 20)
      print('hi world')

if __name__ == "__main__":
  unittest.main()