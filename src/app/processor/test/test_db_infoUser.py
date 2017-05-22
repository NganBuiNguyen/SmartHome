import sys
import os
import unittest

LIDT_ROOT = os.environ['LIDT_ROOT']
sys.path.append(LIDT_ROOT + '/src/app/processor')

import lib_db_manager


class TestSelectInfoUserMethods(unittest.TestCase):

    def test_selectInfoUser(self):
        lib_db_manager_obj = lib_db_manager.LibDBManager()
        expected_result = [
            {
                'idPerson' : 'U0001',
                'grantPerson' : True,
                'userName' : 'kimnganbui',
                'password' : 'nganit123'
            },
            {
                'idPerson' : 'U0002',
                'grantPerson' : False,
                'userName' : 'hongha17',
                'password' : 'hongha123'
            }
        ]

        try:
            result = lib_db_manager_obj.select_infoUser_info()
            self.assertTrue(True)
        except:
            self.assertTrue(False)

        self.assertEqual(expected_result, result)


if __name__ == '__main__':
    unittest.main()