import sys
import os
import unittest

LIDT_ROOT = os.environ['LIDT_ROOT']
sys.path.append(LIDT_ROOT + '/src/app/processor')

import lib_db_manager


class TestSelectRoomMethods(unittest.TestCase):

    def test_selectRoom(self):
        lib_db_manager_obj = lib_db_manager.LibDBManager()
        expected_result = [
            {
                'idRoom': "P0001",
                'nameRoom': "Phong1"
            },
            {
                'idRoom': "P0001",
                'nameRoom': "Phong1"
            }
        ]

        try:
            result = lib_db_manager_obj.select_room_info()
            self.assertTrue(True)
        except:
            self.assertTrue(False)

        self.assertEqual(expected_result, result)


if __name__ == '__main__':
    unittest.main()