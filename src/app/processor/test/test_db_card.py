import sys
import os
import unittest

LIDT_ROOT = os.environ['LIDT_ROOT']
sys.path.append(LIDT_ROOT + '/src/app/processor')

import lib_db_manager


class TestSelectCardMethods(unittest.TestCase):

    def test_selectCard(self):
        lib_db_manager_obj = lib_db_manager.LibDBManager()
        expected_result = [
            {
                'idPerson': 'U0001', 
                'idCard': '5D2A821C'
            },
            {
                'idPerson': 'U0002',
                'idCard': '6628E6EC'
            }
        ]

        try:
            result = lib_db_manager_obj.select_card_info()
            self.assertTrue(True)
        except:
            self.assertTrue(False)
            
        self.assertEqual(expected_result, result)


if __name__ == '__main__':
    unittest.main()