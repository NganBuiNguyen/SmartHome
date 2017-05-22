import sys
import os
import unittest

LIDT_ROOT = os.environ['LIDT_ROOT']
sys.path.append(LIDT_ROOT + '/src/app/processor')

import lib_db_manager


class TestSelectDoorCardMethods(unittest.TestCase):

    def test_selectDoorCard(self):
        lib_db_manager_obj = lib_db_manager.LibDBManager()
        expected_result = [
            {
                'idCard': '5D2A821C',
                'idDoor': 'C0001'
            },
            {
                'idCard': '6628E6EC',
                'idDoor': 'C0002'
            }
        ]

        try:
            result = lib_db_manager_obj.select_doorcard_info()
            self.assertTrue(True)
        except:
            self.assertTrue(False)
        
        self.assertEqual(expected_result, result)

if __name__ == '__main__':
    unittest.main()