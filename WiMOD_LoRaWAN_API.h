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
//------------------------------------------------------------------------------
//
//  Endpoint (SAP) Identifier
//
//------------------------------------------------------------------------------

#define DEVMGMT_SAP_ID                      0x01
#define LORAWAN_SAP_ID                      0x10

//------------------------------------------------------------------------------
//
//  Device Management SAP Message Identifier
//
//------------------------------------------------------------------------------

// Status Identifier
#define	DEVMGMT_STATUS_OK                       0x00
#define	DEVMGMT_STATUS_ERROR                    0x01
#define	DEVMGMT_STATUS_CMD_NOT_SUPPORTED        0x02
#define	DEVMGMT_STATUS_WRONG_PARAMETER          0x03
#define DEVMGMT_STATUS_WRONG_DEVICE_MODE        0x04

// Message Identifier
#define DEVMGMT_MSG_PING_REQ                    0x01
#define DEVMGMT_MSG_PING_RSP                    0x02

#define DEVMGMT_MSG_GET_DEVICE_INFO_REQ         0x03
#define DEVMGMT_MSG_GET_DEVICE_INFO_RSP         0x04

#define DEVMGMT_MSG_GET_FW_VERSION_REQ          0x05
#define DEVMGMT_MSG_GET_FW_VERSION_RSP          0x06

#define LORAWAN_MSG_SET_RSTACK_CONFIG_REQ 			0x19
#define LORAWAN_MSG_SET_RSTACK_CONFIG_RSP 			0x1A
#define LORAWAN_MSG_GET_RSTACK_CONFIG_REQ 			0x1B
#define LORAWAN_MSG_GET_RSTACK_CONFIG_RSP 			0x1C

//------------------------------------------------------------------------------
//
//  LoRaWAN SAP Message Identifier
//
//------------------------------------------------------------------------------

// Status Identifier
#define LORAWAN_STATUS_OK                       0x00
#define	LORAWAN_STATUS_ERROR                    0x01
#define	LORAWAN_STATUS_CMD_NOT_SUPPORTED        0x02
#define	LORAWAN_STATUS_WRONG_PARAMETER          0x03
#define LORAWAN_STATUS_WRONG_DEVICE_MODE        0x04
#define LORAWAN_STATUS_NOT_ACTIVATED            0x05
#define LORAWAN_STATUS_BUSY                     0x06
#define LORAWAN_STATUS_QUEUE_FULL               0x07
#define LORAWAN_STATUS_LENGTH_ERROR             0x08
#define LORAWAN_STATUS_NO_FACTORY_SETTINGS      0x09
#define LORAWAN_STATUS_CHANNEL_BLOCKED_BY_DC    0x0A
#define LORAWAN_STATUS_CHANNEL_NOT_AVAILABLE    0x0B

// Message Identifier

#define LORAWAN_MSG_ACTIVATE_DEVICE_REQ					0x01
#define LORAWAN_MSG_ACTIVATE_DEVICE_RSP					0x02
#define LORAWAN_MSG_JOIN_NETWORK_REQ            0x09
#define LORAWAN_MSG_JOIN_NETWORK_RSP            0x0A
#define LORAWAN_MSG_JOIN_TRANSMIT_IND           0x0B
#define LORAWAN_MSG_JOIN_NETWORK_IND            0x0C

#define LORAWAN_MSG_SEND_UDATA_REQ              0x0D
#define LORAWAN_MSG_SEND_UDATA_RSP              0x0E
#define LORAWAN_MSG_SEND_UDATA_IND              0x0F
#define LORAWAN_MSG_RECV_UDATA_IND              0x10

#define LORAWAN_MSG_SEND_CDATA_REQ              0x11
#define LORAWAN_MSG_SEND_CDATA_RSP              0x12
#define LORAWAN_MSG_SEND_CDATA_IND              0x13
#define LORAWAN_MSG_RECV_CDATA_IND              0x14

#define LORAWAN_MSG_RECV_ACK_IND                0x15
#define LORAWAN_MSG_RECV_NODATA_IND             0x16
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
// send an activation request
int WiMOD_LoRaWAN_ABP_Activate(unsigned char* DeviceAddress ,unsigned char* NetworkSessionKey , unsigned char* ApplicationSessionKey);
// Receiver Process
void WiMOD_LoRaWAN_Process();
//------------------------------------------------------------------------------
// end of file
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#endif /* WIMOD_LORAWAN_API_H_ */
