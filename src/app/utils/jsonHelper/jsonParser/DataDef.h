#ifndef __DATA_STRUCT_DEF_H__
#define __DATA_STRUCT_DEF_H__

#include <iostream>
#include <string.h>
#include <string>

struct Sender
{
    char ip[20];
    long port;
};

struct OpenDoor
{
     char cardID[25];
};

struct CardInfo
{
    OpenDoor data;
    Sender sender;

};

#endif