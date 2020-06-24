/*
 * WiMOD_LoRaWAN_API.h
 *
 *  Created on: Apr 30, 2020
 *      Author: AminZaky
 */

#ifndef WIMOD_LORAWAN_API_H_
#define WIMOD_LORAWAN_API_H_
//------------------------------------------------------------------------------
//
// Include Files
//
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//
// Endpoint (SAP) Identifier
//
//------------------------------------------------------------------------------
#define DEVMGMT_SAP_ID 0x01
#define LORAWAN_SAP_ID 0x10
//------------------------------------------------------------------------------
//
// Device Management SAP Message Identifier
//
//------------------------------------------------------------------------------
#define DEVMGMT_MSG_PING_REQ 0x01
#define DEVMGMT_MSG_PING_RSP 0x02
//------------------------------------------------------------------------------
//
// LoRaWAN SAP Message Identifier
//
//------------------------------------------------------------------------------
#define LORAWAN_MSG_SEND_UDATA_REQ 0x0D
#define LORAWAN_MSG_SEND_UDATA_RSP 0x0E
#define LORAWAN_MSG_SEND_UDATA_IND 0x0F
#define LORAWAN_MSG_RECV_UDATA_IND 0x10
#define LORAWAN_MSG_SEND_CDATA_REQ 0x11
#define LORAWAN_MSG_SEND_CDATA_RSP 0x12
#define LORAWAN_MSG_SEND_CDATA_IND 0x13
#define LORAWAN_MSG_RECV_CDATA_IND 0x14
#define LORAWAN_MSG_RECV_ACK_IND 0x15
#define LORAWAN_MSG_RECV_NODATA_IND 0x16
//------------------------------------------------------------------------------
//
// Function Prototypes
//
//------------------------------------------------------------------------------
// Init
void WiMOD_LoRaWAN_Init();
// Send Ping
int WiMOD_LoRaWAN_SendPing();
// Send unconfirmed radio data
int WiMOD_LoRaWAN_SendURadioData(uint8 port, uint8* data, int length);
// Send confirmed radio data
int WiMOD_LoRaWAN_SendCRadioData(uint8 port, uint8* data, int length);
// Receiver Process
void WiMOD_LoRaWAN_Process();
//------------------------------------------------------------------------------
// end of file
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#endif /* WIMOD_LORAWAN_API_H_ */
