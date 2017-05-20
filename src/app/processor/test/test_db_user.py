import sys
import os
import unittest

LIDT_ROOT = os.environ['LIDT_ROOT']
sys.path.append(LIDT_ROOT + '/src/app/processor')

import lib_db_manager


class TestSelectUserMethods(unittest.TestCase):

    def test_selectUser(self):
        lib_db_manager_obj = lib_db_manager.LibDBManager()
        expected_result = [
            {
                'idPerson' : 'U0001',
                'namePerson' : 'Ngan',
                'age' : 21
            },
            {
                'idPerson' : 'U0001',
                'namePerson' : 'Ngan',
                'age' : 21
            }
        ]

        try:
            result = lib_db_manager_obj.select_person_info()
            self.assertTrue(True)
        except:
            self.assertTrue(False)

        self.assertEqual(expected_result, result)


if __name__ == '__main__':
    unittest.main()