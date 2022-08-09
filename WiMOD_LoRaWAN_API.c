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
#include "Std_Types.h"
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
	//LCD_vidInit4();
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
//  ABP_Activate
//
//  @brief: join network
//
//------------------------------------------------------------------------------

int
WiMOD_LoRaWAN_ABP_Activate(unsigned char* DeviceAddress ,unsigned char* NetworkSessionKey , unsigned char* ApplicationSessionKey)
{
	  // 1. init header

    TxMessage.SapID     = LORAWAN_SAP_ID;
    TxMessage.MsgID     = LORAWAN_MSG_ACTIVATE_DEVICE_REQ ;
    TxMessage.Length    = 36;

    TxMessage.Payload[0] = DeviceAddress[0] ;
    TxMessage.Payload[1] = DeviceAddress[1] ;
    TxMessage.Payload[2] = DeviceAddress[2] ;
    TxMessage.Payload[3] = DeviceAddress[3] ;


    TxMessage.Payload[4] =  (NetworkSessionKey[15]) ;
    TxMessage.Payload[5] =  (NetworkSessionKey[14]) ;
    TxMessage.Payload[6] =  (NetworkSessionKey[13]) ;
    TxMessage.Payload[7] =  (NetworkSessionKey[12]) ;
    TxMessage.Payload[8] =  (NetworkSessionKey[11]) ;
    TxMessage.Payload[9] =  (NetworkSessionKey[10]) ;
    TxMessage.Payload[10] = (NetworkSessionKey[9])  ;
    TxMessage.Payload[11] = (NetworkSessionKey[8])  ;
    TxMessage.Payload[12] = (NetworkSessionKey[7])  ;
    TxMessage.Payload[13] = (NetworkSessionKey[6])  ;
    TxMessage.Payload[14] = (NetworkSessionKey[5])  ;
    TxMessage.Payload[15] = (NetworkSessionKey[4])  ;
    TxMessage.Payload[16] = (NetworkSessionKey[3])  ;
    TxMessage.Payload[17] = (NetworkSessionKey[2])  ;
    TxMessage.Payload[18] = (NetworkSessionKey[1])  ;
    TxMessage.Payload[19] = (NetworkSessionKey[0])  ;



    // must check whether its Little or big Endian .


    TxMessage.Payload[20] = (ApplicationSessionKey[15])  ;
    TxMessage.Payload[21] = (ApplicationSessionKey[14])  ;
    TxMessage.Payload[22] = (ApplicationSessionKey[13])  ;
    TxMessage.Payload[23] = (ApplicationSessionKey[12])  ;
    TxMessage.Payload[24] = (ApplicationSessionKey[11])  ;
    TxMessage.Payload[25] = (ApplicationSessionKey[10])  ;
    TxMessage.Payload[26] = (ApplicationSessionKey[9])  ;
    TxMessage.Payload[27] = (ApplicationSessionKey[8])  ;
    TxMessage.Payload[28] = (ApplicationSessionKey[7])  ;
    TxMessage.Payload[29] = (ApplicationSessionKey[6])  ;
    TxMessage.Payload[30] = (ApplicationSessionKey[5])  ;
    TxMessage.Payload[31] = (ApplicationSessionKey[4])  ;
    TxMessage.Payload[32] = (ApplicationSessionKey[3])  ;
    TxMessage.Payload[33] = (ApplicationSessionKey[2])  ;
    TxMessage.Payload[34] = (ApplicationSessionKey[1])  ;
    TxMessage.Payload[35] = (ApplicationSessionKey[0])  ;


    // 2. send HCI message without payload
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

