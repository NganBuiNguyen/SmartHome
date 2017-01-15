#ifndef __JSON_PARSER_H__
#define __JSON_PARSER_H__

#include "DataDef.h"
#include "JsonCommon.h"

bool parseOpenDoorJson(const std::string& jsonString, CardInfo& info);

#endif