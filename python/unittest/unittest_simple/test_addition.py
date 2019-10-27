import unittest
from addition import addition

class TestAddition(unittest.TestCase):
    def test_addition(self):
        value1 = 2
        value2 = 3
        expected = 5
        actual = addition(value1, value2)
        self.assertEqual(expected, actual)

if __name__ == "__main__":
    unittest.main()