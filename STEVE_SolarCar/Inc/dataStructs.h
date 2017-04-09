/*
 * dataStructs.h
 *
 *  Created on: 9 Apr 2017
 *      Author: fredr_000
 */

#ifndef DATASTRUCTS_H_
#define DATASTRUCTS_H_



struct PDO1
{
	u_int8_t minVolt; //0,01V/bit
	u_int8_t minVoltID;
	u_int8_t maxVolt; //0,01V/bit
	u_int8_t maxVoltID;
	u_int16_t volt; //0,01V/bit
	int16_t cuttent; // 0,1A/bit
};

struct PDO2
{
	u_int16_t SOC; //0,1%/bit
	int16_t minTemp; //0,1%/bit
	int16_t maxTemp; //0,1%/bit
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
	struct MotorFrame0 frame0;
	struct MotorFrame0 frame1;
	struct MotorFrame0 frame2;
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
	//todo
};

#endif /* DATASTRUCTS_H_ */
