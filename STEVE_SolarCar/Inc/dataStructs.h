/*
 * dataStructs.h
 *
 *  Created on: 9 Apr 2017
 *      Author: fredr_000
 */

#ifndef DATASTRUCTS_H_
#define DATASTRUCTS_H_

struct CANidSend
{
	u_int16_t MPPT = 0x719;
	u_int16_t BMS = 0x180;
	u_int64_t motorController = 0x08F91540;



};

struct CANidReceive
{
	u_int16_t MPPT = 0x779;
	u_int16_t BMSPDO1 = 0x200;
	u_int16_t BMSPDO2 = 0x300;
	u_int16_t BMSPDO3 =	0x400
	u_int64_t motorFrame0 = 0x08850245;
	u_int64_t motorFrame1 = 0x08950245;
	u_int64_t motorFrame2 = 0x08A50245
};


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
