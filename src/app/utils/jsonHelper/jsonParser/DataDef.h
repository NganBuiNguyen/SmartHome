#ifndef __DATA_STRUCT_DEF_H__
#define __DATA_STRUCT_DEF_H__

#include <iostream>
#include <string.h>
#include <string>

typedef struct
  {
     char ip[20];
     long port;
  }Sender;

typedef struct
  {
      char cardID[25];
  }OpenDoor;

typedef struct
  {
     OpenDoor data;
     Sender sender;

  }CardInfo;

#endif