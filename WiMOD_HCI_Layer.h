/*
 * WiMOD_HCI_Layer.h
 *
 *  Created on: Apr 30, 2020
 *      Author: AminZaky
 */

#ifndef WIMOD_HCI_LAYER_H_
#define WIMOD_HCI_LAYER_H_
//------------------------------------------------------------------------------
//
// Include Files
//
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//
// General Declarations & Definitions
//
//------------------------------------------------------------------------------
#define WIMOD_HCI_MSG_HEADER_SIZE 2
#define WIMOD_HCI_MSG_PAYLOAD_SIZE 300
#define WIMOD_HCI_MSG_FCS_SIZE 2
#define LOBYTE(x) (x)
#define HIBYTE(x) ((uint16)(x) >> 8)
//------------------------------------------------------------------------------
//
// HCI Message Structure (internal software usage)
//
//------------------------------------------------------------------------------
typedef struct {
	// Payload Length Information,
	// this field not transmitted over UART interface !!!
	uint16 Length;
	// Service Access Point Identifier
	uint8 SapID;
	// Message Identifier
	uint8 MsgID;
	// Payload Field
	uint8 Payload[WIMOD_HCI_MSG_PAYLOAD_SIZE];
	// Frame Check Sequence Field
	uint8 CRC16[WIMOD_HCI_MSG_FCS_SIZE];
} TWiMOD_HCI_Message;
//------------------------------------------------------------------------------
//
// Function Prototypes
//
//------------------------------------------------------------------------------
// Message receiver callback
typedef TWiMOD_HCI_Message* (*TWiMOD_HCI_CbRxMessage)(
		TWiMOD_HCI_Message* rxMessage);
// Init HCI Layer
bool WiMOD_HCI_Init(TWiMOD_HCI_CbRxMessage cbRxMessage,TWiMOD_HCI_Message* rxMessage);
// Send HCI Message
int WiMOD_HCI_SendMessage(TWiMOD_HCI_Message* txMessage);
// Receiver Process
void WiMOD_HCI_Process();
//------------------------------------------------------------------------------
// end of file
//------------------------------------------------------------------------------
#endif /* WIMOD_HCI_LAYER_H_ */
