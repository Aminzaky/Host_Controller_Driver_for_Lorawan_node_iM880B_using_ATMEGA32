/*
 * SLIP.h
 *
 *  Created on: Apr 30, 2020
 *      Author: AminZaky
 */

#ifndef SLIP_H_
#define SLIP_H_

//------------------------------------------------------------------------------
//
// Include Files
//
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//
// Function Prototypes
//
//------------------------------------------------------------------------------
// SLIP message receiver callback
typedef uint8* (*TSLIP_CbRxMessage)(uint8* message, int length);
// Init SLIP layer
void SLIP_Init(TSLIP_CbRxMessage cbRxMessage);
// Init first receiver buffer
bool SLIP_SetRxBuffer(uint8* rxBuffer, int rxBufferSize);
// Encode outgoing Data
int SLIP_EncodeData(uint8* dstBuffer, int txBufferSize, uint8* srcData,
		int srcLength);
// Decode incoming Data
void SLIP_DecodeData(uint8* srcData, int srcLength);

//------------------------------------------------------------------------------
// end of file
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif /* SLIP_H_ */
