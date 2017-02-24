#include "JsonParserForC.h"
#include "JsonParser.h"

/*!
 * @internal
 */
bool parseOpenDoorJsonForC(const char* jsonString, CardInfo* info)
{
    return parseOpenDoorJson(std::string(jsonString), *info);
}