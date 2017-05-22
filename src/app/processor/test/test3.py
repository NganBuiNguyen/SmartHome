import sys
import os
import unittest

LIDT_ROOT = os.environ['LIDT_ROOT']
sys.path.append(LIDT_ROOT + '/src/app/processor')

import lib_db_manager


class TestMethods(unittest.TestCase):

    def test_test(self):
        lib_db_manager_obj = lib_db_manager.LibDBManager()
        # try:
        result = lib_db_manager_obj.check_card()
        #     self.assertTrue(True)
        # except:
        #     self.assertTrue(False)

        # self.assertEqual(expected_result, result)


if __name__ == '__main__':
    unittest.main()