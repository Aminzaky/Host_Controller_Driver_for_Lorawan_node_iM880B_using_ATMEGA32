/*
 * WiMOD_LoRaWAN_API.c
 *
 *  Created on: Apr 30, 2020
 *      Author: AminZaky
 */

//------------------------------------------------------------------------------
//
// Include Files
//
//------------------------------------------------------------------------------
#include "WiMOD_LoRaWAN_API.h"
#include "WiMOD_HCI_Layer.h"
#include <string.h>
//------------------------------------------------------------------------------
//
// Forward Declarations
//
//------------------------------------------------------------------------------
// HCI Message Receiver callback
static TWiMOD_HCI_Message*
WiMOD_LoRaWAN_Process_RxMessage(TWiMOD_HCI_Message* rxMessage);
static void
WiMOD_LoRaWAN_Process_DevMgmt_Message(TWiMOD_HCI_Message* rxMessage);
static void
WiMOD_LoRaWAN_Process_LoRaWAN_Message(TWiMOD_HCI_Message* rxMessage);
//------------------------------------------------------------------------------
//
// Section RAM
//
//------------------------------------------------------------------------------
// reserve one TxMessage
TWiMOD_HCI_Message TxMessage;
// reserve one RxMessage
TWiMOD_HCI_Message RxMessage;
//------------------------------------------------------------------------------
//
// Section Code
//
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//
// Init
//
// @brief: init complete interface
//
//------------------------------------------------------------------------------
void WiMOD_LoRaWAN_Init() {
	// init HCI layer
	WiMOD_HCI_Init(WiMOD_LoRaWAN_Process_RxMessage, // receiver callback
			&RxMessage); // rx message
	LCD_vidInit4();
}
//------------------------------------------------------------------------------
//
// Ping
//
// @brief: send a ping message
//
//------------------------------------------------------------------------------
int WiMOD_LoRaWAN_SendPing() {
	// 1. init header
	TxMessage.SapID = DEVMGMT_SAP_ID;
	TxMessage.MsgID = DEVMGMT_MSG_PING_REQ;
	TxMessage.Length = 0;
	// 2. send HCI message without payload
	return WiMOD_HCI_SendMessage(&TxMessage);
}
//------------------------------------------------------------------------------
//
// SendURadioData
//
// @brief: send unconfirmed radio message
//
//------------------------------------------------------------------------------
int WiMOD_LoRaWAN_SendURadioData(uint8 port, uint8* srcData, int srcLength) {
	// 1. check length
	if (srcLength > (WIMOD_HCI_MSG_PAYLOAD_SIZE - 1)) {
		// error
		return -1;
	}
	// 2. init header
	TxMessage.SapID = LORAWAN_SAP_ID;
	TxMessage.MsgID = LORAWAN_MSG_SEND_UDATA_REQ;
	TxMessage.Length = 1 + srcLength;
	// 3. init payload
	// 3.1 init port
	TxMessage.Payload[0] = port;
	// 3.2 init radio message payload
	memcpy(&TxMessage.Payload[1], srcData, srcLength);
	// 4. send HCI message with payload
	return WiMOD_HCI_SendMessage(&TxMessage);
}
//------------------------------------------------------------------------------
//
// SendCRadioData
//
// @brief: send confirmed radio message
//
//------------------------------------------------------------------------------
int WiMOD_LoRaWAN_SendCRadioData(uint8 port, uint8* srcData, int srcLength) {
	// 1. check length
	if (srcLength > (WIMOD_HCI_MSG_PAYLOAD_SIZE - 1)) {
		// error
		return -1;
	}
	// 2. init header
	TxMessage.SapID = LORAWAN_SAP_ID;
	TxMessage.MsgID = LORAWAN_MSG_SEND_CDATA_REQ;
	TxMessage.Length = 1 + srcLength;
	// 3. init payload
	// 3.1 init port
	TxMessage.Payload[0] = port;
	// 3.2 init radio message payload
	memcpy(&TxMessage.Payload[1], srcData, srcLength);
	// 4. send HCI message with payload
	return WiMOD_HCI_SendMessage(&TxMessage);
}
//------------------------------------------------------------------------------
//
// Process
//
// @brief: handle receiver process
//
//------------------------------------------------------------------------------
void WiMOD_LoRaWAN_Process() {
	// call HCI process
	WiMOD_HCI_Process();
}
//------------------------------------------------------------------------------
//
// Process
//
// @brief: handle receiver process
//
//------------------------------------------------------------------------------
static TWiMOD_HCI_Message*
WiMOD_LoRaWAN_Process_RxMessage(TWiMOD_HCI_Message* rxMessage) {
	switch (rxMessage->SapID) {
	case DEVMGMT_SAP_ID:
		WiMOD_LoRaWAN_Process_DevMgmt_Message(rxMessage);
		break;
	case LORAWAN_SAP_ID:
		WiMOD_LoRaWAN_Process_LoRaWAN_Message(rxMessage);
		break;
	}
	return &RxMessage;
}
//------------------------------------------------------------------------------
//
// Process_DevMgmt_Message
//
// @brief: handle received Device Management SAP messages
//
//------------------------------------------------------------------------------
static void WiMOD_LoRaWAN_Process_DevMgmt_Message(TWiMOD_HCI_Message* rxMessage) {
	char temp[2];
	switch (rxMessage->MsgID) {
	case DEVMGMT_MSG_PING_RSP:
		//printf("Ping Response, Status : 0x%02X\n\r",
		//	(uint8) rxMessage->Payload[0]);
		LCD_VidWriteCommand4(0x01);
		LCD_String4("Ping Response");
		LCD_Goto_row_coulmn4(1, 0);
		LCD_String4("Status : 0x");
		(itoa(((uint8) rxMessage->Payload[0])), temp, 16);
		LCD_String4(temp);
		break;
	default:
		//printf("unhandled DeviceMgmt message received - MsgID : 0x%02X\n\r",
		//(uint8) rxMessage->MsgID);
		LCD_VidWriteCommand4(0x01);
		LCD_String4("DevMgmt msg recv");
		LCD_Goto_row_coulmn4(1, 0);
		LCD_String4("MsgID : 0x");
		(itoa(((uint8) rxMessage->MsgID)), temp, 16);
		LCD_String4(temp);
		break;
	}
}
//------------------------------------------------------------------------------
//
// Process_LoRaWAN_Message
//
// @brief: handle received LoRaWAN SAP messages
//
//------------------------------------------------------------------------------
static void WiMOD_LoRaWAN_Process_LoRaWAN_Message(TWiMOD_HCI_Message* rxMessage) {
	char temp[2];
	switch (rxMessage->MsgID) {
	case LORAWAN_MSG_SEND_UDATA_RSP:
		//printf("Send U-Data Response, Status : 0x%02X\n\r",
		//(uint8) rxMessage->Payload[0]);
		LCD_VidWriteCommand4(0x01);
		LCD_String4("Send U-Data Res");
		LCD_Goto_row_coulmn4(1, 0);
		LCD_String4("Status : 0x");
		(itoa(((uint8) rxMessage->Payload[0])), temp, 16);
		LCD_String4(temp);
		break;
	case LORAWAN_MSG_SEND_CDATA_RSP:
		//printf("Send C-Data Response, Status : 0x%02X\n\r",
		//		(uint8) rxMessage->Payload[0]);
		LCD_VidWriteCommand4(0x01);
		LCD_String4("Send C-Data Res");
		LCD_Goto_row_coulmn4(1, 0);
		LCD_String4("Status : 0x");
		(itoa(((uint8) rxMessage->Payload[0])), temp, 16);
		LCD_String4(temp);
		break;
	default:
		//printf("unhandled LoRaWAN SAP message received - MsgID : 0x%02X\n\r",
		//		(uint8) rxMessage->MsgID);
		LCD_VidWriteCommand4(0x01);
		LCD_String4("SAP msg recv");
		LCD_Goto_row_coulmn4(1, 0);
		LCD_String4("MsgID : 0x");
		(itoa(((uint8) rxMessage->MsgID)), temp, 16);
		LCD_String4(temp);
		break;
	}
}
//------------------------------------------------------------------------------
// end of file
//------------------------------------------------------------------------------

