/***************************************************************************/
/*!
 * @file JsonBuilderForC.h
 * @brief
 *
 * Copyright (c) Tien Nguyen Anh
 *
 * @detail
 *
 * Modified History
 * ---------------
 * 2017-Jan-07 Created tien.nguyenanh94@gmail.com
 */
/***************************************************************************/

#ifndef __JSON_BUILDER_FOR_C__
#define __JSON_BUILDER_FOR_C__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"{
#endif

/*!
 * @brief
 * param[in] message
 * return
 */
bool buildJsonForC(const char* message, char** jsonString);

#ifdef __cplusplus
}
#endif

#endif