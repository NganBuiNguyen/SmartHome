/***************************************************************************/
/*!
 * @file JsonSenderForC.h
 * @brief
 *
 * Copyright (c) Tien Nguyen Anh
 *
 * @detail
 *
 * Modified History
 * ---------------
 * 2017-Jan-08 Created tien.nguyenanh94@gmail.com
 */
/***************************************************************************/

#ifndef __MESSAGE_SENDER_FOR_C_H__
#define __MESSAGE_SENDER_FOR_C_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"{
#endif

bool sendMessageUDPForC(const char* data, const char* host,
                                                        unsigned int port);
bool sendMessageTCPForC(const char* data, const char* host,
                                                        unsigned int port);
#ifdef __cplusplus
}
#endif

#endif