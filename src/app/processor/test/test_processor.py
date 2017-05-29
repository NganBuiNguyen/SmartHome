import sys
import os
import json
import unittest


LIDT_ROOT = os.environ['LIDT_ROOT']
sys.path.append(LIDT_ROOT + '/src/app/processor')

import processor
import constants

class TestProcessorMethods(unittest.TestCase):

    def test_get_all_doors(self):
        processor_oj = processor.Processor(host=192, 
                                                            port=5563)
        expected_result = [
            {
                'idDoor': 'C0001',
                'nameDoor': 'Cua1',
                'ip': '192.168.3.177',
                'port' : 6203,
                'idRoom': 'P0001'
            },
            {
                'idDoor': 'C0002',
                'nameDoor': 'Cua2',
                'ip': '192.168.3.103',
                'port' : 5563,
                'idRoom': 'P0002'
            }
        ]

        try:
            result = processor_oj.get_all_doors()
            print("\n\n select processor:", result)
            self.assertTrue(True)
        except:
            self.assertTrue(False)

        self.assertEqual(expected_result, result)

    def test_get_card_ids(self):
        processor_oj = processor.Processor(host=192, port=5563)

        expected_result1 = [
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
            result = processor_oj.get_card_ids()
            print("\n\n select processor:", result)
            self.assertTrue(True)
        except:
            self.assertTrue(False)

        self.assertEqual(expected_result1, result)

    def test_get_card_doors(self):
        processor_oj = processor.Processor(host=192, port=5563)

        expected_result = [
            {
                'id'    : 1,
                'idCard': '5D2A821C',
                'idDoor': 'C0001'
            },
            {
                'id'    : 2,
                'idCard': '6628E6EC',
                'idDoor': 'C0002'
            }
        ]

        try:
            result = processor_oj.get_card_doors()
            print("\n\n select processor:", result)
            self.assertTrue(True)
        except:
            self.assertTrue(False)

        self.assertEqual(expected_result, result)

if __name__ == '__main__':
    unittest.main()
        