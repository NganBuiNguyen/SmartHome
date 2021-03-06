#ifndef __JSON_BUILDER_H__
#define __JSON_BUILDER_H__

#include "JsonCommon.h"

/*!
 * @brief
 * param[in] message
 * return
 */
bool buildJson(const std::string& message, std::string& jsonString);

// std::string writeJsonToString(boost::property_tree::ptree& pTree);

#endif