/*
 * dataStructs.h
 *
 *  Created on: 9 Apr 2017
 *      Author: fredr_000
 */

#ifndef DATASTRUCTS_H_
#define DATASTRUCTS_H_

#include "stm32l4xx_hal.h"

/*
 * Copy and paste the following consts in the file where you need the id:s
 * When creating the structs do as follows
 *
 * struct CANidSend SendIds = CANidSend_defaults;
 * struct CANidReceive ReceiveIds = CANidReceive_defaults;
 *
 * this will init the structs to their correct id values for you
 *
const struct CANidReceive CANidReceive_defaults =  {0x779, 0x200, 0x300, 0x400, 0x08850245, 0x08950245, 0x08A50245};
const struct CANidSend CANidSend_defaults = {0x719, 0x180, 0x08F91540};
*/


struct CANidSend
{
	u_int16_t MPPT;
	u_int16_t BMS;
	u_int64_t motorControler;
};



struct CANidReceive
{
	u_int16_t MPPT;
	u_int16_t BMSPDO1;
	u_int16_t BMSPDO2;
	u_int16_t BMSPDO3;
	u_int64_t motorFrame0;
	u_int64_t motorFrame1;
	u_int64_t motorFrame2;
};


struct PDO1
{
	u_int8_t minVolt; //0,01V/bit
	u_int8_t minVoltID;
	u_int8_t maxVolt; //0,01V/bit
	u_int8_t maxVoltID;
	u_int16_t volt; //0,01V/bit
	int16_t current; // 0,1A/bit
};

struct PDO2
{
	u_int16_t SOC; //0,1%/bit
	u_int16_t minTemp; //0,1%/bit
	u_int16_t maxTemp; //0,1%/bit
	u_int8_t minTempID;
	u_int8_t maxTempID;
};

struct PDO3
{
	// todo?
};

struct MPPT
{
	u_int8_t flags;
	u_int8_t uinLSB;
	u_int8_t linMSBtbd; //LinMSB & TBD
	u_int8_t linLSB;
	u_int8_t uoutMSBtbd; //UoutMSB & TBD
	u_int8_t uoutLSB;
	u_int8_t tamb;
};

struct Motor
{
	struct MotorFrame0 *frame0;
	struct MotorFrame0 *frame1;
	struct MotorFrame0 *frame2;
};

struct MotorFrame0
{
	u_int16_t batteryVoltage; //0,5V/LSB
	u_int16_t batteryCurrent; //1A/LSB
	u_int8_t batteryCurrentDirection;
	u_int16_t motorCurrentPeakAvrage; //1/LSB
	u_int8_t fetTemp; //5°C/LSB
	u_int16_t motorRotationgSpeed; //1rpm/LSB
	u_int16_t PWMduty; //0,5%/LSB
	u_int8_t leadAngle; //0,5°/LSB
};

struct MotorFrame1
{
	u_int8_t status; // Power mode, motor control mode, drive action status, regneration status.
	u_int16_t acceleratorPos; //0,5%/LSB
	u_int16_t regnerationVrPos; //0,5%/LSB
	u_int8_t digitSwPos;
	u_int16_t outputTargetVal; //0,5%/LSB
};

struct MotorFrame2
{
	/**
	 * @Analog Sensor Error 				bit 0
	 * Motor Current Sensor U Error			bit 1
	 * Motor Current Sensor W Error			bit 2
	 * FET Thermistor Error					bit 3
	 * TBD									bit 4
	 * Battery Voltage Sensor Error			bit 5
	 * Battery Current Sensor Error			bit 6
	 * Battery Current Sensor Adjust Error	bit 7
	 * Motor Current Sensor Adjust Error	bit 8
	 * Accelerator Position Error			bit 9
	 * TBD									bit 10
	 * Controller Voltage Sensor Error		bit 11
	 * TBD									bit 12-15
	 * Power System Error					bit 16
	 * Over Current Error					bit 17
	 * TBD									bit 18
	 * Over Voltage Error					bit 19
	 * TBD									bit 20
	 * Over Current Limit					bit 21
	 * TBD									bit 22-23
	 * Motor System Error					bit 24
	 * Motor Lock							bit 25
	 * Hall Sensor Short					bit 26
	 * Hall Sensor Open						bit 27
	 * TBD									bit 28-31
	 * Over Heat Level						bit 32-33
	 */
	u_int64_t flags;
};






#endif /* DATASTRUCTS_H_ */
