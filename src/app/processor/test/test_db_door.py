import sys
import os
import unittest

LIDT_ROOT = os.environ['LIDT_ROOT']
sys.path.append(LIDT_ROOT + '/src/app/processor')

import lib_db_manager


class TestSelectDoorMethods(unittest.TestCase):

    def test_selectDoor(self):
        lib_db_manager_obj = lib_db_manager.LibDBManager()
        expected_result = [
            {
                'idDoor': 'C0001',
                'nameDoor': 'Cua1',
                'ip': '192.168.3.100',
                'port' : 5563,
                'idRoom': 'P0001'
            },
            {
                'idDoor': 'C0001',
                'nameDoor': 'Cua1',
                'ip': '192.168.3.100',
                'port' : 5563,
                'idRoom': 'P0001'
            }
        ]

        try:
            result = lib_db_manager_obj.select_door_info()
            self.assertTrue(True)
        except:
            self.assertTrue(False)

        self.assertEqual(expected_result, result)


if __name__ == '__main__':
    unittest.main()