#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <string.h>
#include <string>
#include <stdint.h>
#include <regex>
#include <math.h>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "/data/SmartHome/src/app/dataConverter/DataDef.h"

MESSAGE_TYPE getJSONMessageType(const std::string& message);

bool isSensorMessage(const std::string& message);

std::string convertMessageTypeToStr(const MESSAGE_TYPE& messageType);

bool convertJsonStrToPtree(const std::string& jsonString,
                                    boost::property_tree::ptree& dataTree);

 

#endif
