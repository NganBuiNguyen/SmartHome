"""
File: optionParser.py
=========================

Copyright (c) Tien Nguyen Anh

Modified History
----------------
2017-Jan-09 Created tien.nguyenanh94@gmail.com
"""
import sys

def parseCmdLineArg(cmd_line_arg):

    host = cmd_line_arg[1]
    port = cmd_line_arg[2]

    topic = []
    for index in range(0, len(cmd_line_arg)):
        if (index > 2):
            topic.append(cmd_line_arg[index])

    return host, port, topic 