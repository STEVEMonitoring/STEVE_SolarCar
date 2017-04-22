/*
 * CANdataConv.c
 *
 *  Created on: 9 Apr 2017
 *      Author: fredr_000
 */

#include "dataStructs.h"
#include "CANdataConv.h"

void setMotorContent(u_int64_t *content, struct Motor *motor)
{


}

void setPDO1(u_int64_t content, struct PDO1 *pdo1)
{

	pdo1->minVolt = (content 	& 0x00000000000000FF);
	pdo1->minVoltID = (content	& 0x000000000000FF00) >> 8;
	pdo1->maxVolt = (content 	& 0x0000000000FF0000) >> 16;
	pdo1->maxVoltID = (content 	& 0x00000000FF000000) >> 24;
	pdo1->volt = (content 		& 0x0000FFFF00000000) >> 32;
	pdo1->current = (content 	& 0xFFFF000000000000) >> 48;
}

void setPDO2(u_int64_t content, struct PDO2 *pdo2)
{
	pdo2->SOC = (content 		& 0x000000000000FFFF);
	pdo2->minTemp = (content 	& 0x00000000FFFF0000) >> 16;
	pdo2->maxTemp = (content 	& 0x0000FFFF00000000) >> 32;
	pdo2->minTempID = (content 	& 0x00FF000000000000) >> 48;
	pdo2->maxTempID = (content 	& 0xFF00000000000000) >> 56;
}


