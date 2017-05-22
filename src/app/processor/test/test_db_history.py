import sys
import os
import unittest

LIDT_ROOT = os.environ['LIDT_ROOT']
sys.path.append(LIDT_ROOT + '/src/app/processor')

import lib_db_manager


class TestSelectHistoryMethods(unittest.TestCase):

    def test_selectHistory(self):
        lib_db_manager_obj = lib_db_manager.LibDBManager()
        expected_result = [
            {
                'day' : 7,
                'month' : 5,
                'year' : 2017,
                'hour' : 9,
                'min' : 42,
                'sec' : 15,
                'statusDoor' : True,
                'checkCard' : True
            },
            {
                'day' : 7,
                'month' : 5,
                'year' : 2017,
                'hour' : 13,
                'min' : 12,
                'sec' : 35,
                'statusDoor' : True,
                'checkCard' : True
            }
        ]

        try:
            result = lib_db_manager_obj.select_history_info()
            self.assertTrue(True)
        except:
            self.assertTrue(False)

        self.assertEqual(expected_result, result)


if __name__ == '__main__':
    unittest.main()