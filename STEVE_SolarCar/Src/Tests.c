/*
 * Tests.c
 *
 *  Created on: 22 Apr 2017
 *      Author: fredr_000
 */


#include "Tests.h"


char testCANdataConv()
{



	u_int64_t content = 0x0123456789ABCDEF;

	char tests = 0x7F;

	struct PDO1 pdo1;
	struct PDO2 pdo2;
	//struct PDO3 pdo3;

	// PDO1 test start
	setPDO1(content, &pdo1);


	if(pdo1.minVolt 	!= 0xEF ||
	   pdo1.minVoltID 	!= 0xCD ||
	   pdo1.maxVolt 	!= 0xAB ||
	   pdo1.maxVoltID 	!= 0x89 ||
	   pdo1.volt 		!= 0x4567 ||
	   pdo1.current 	!= 0x0123)
	{
		tests = tests & 0xFE;
	}
	//PDO1 test end


	//PDO2 test start
	setPDO2(content, &pdo2);

	if(pdo2.SOC 		!= 0xCDEF ||
	   pdo2.minTemp 	!= 0x89AB ||
	   pdo2.maxTemp 	!= 0x4567 ||
	   pdo2.minTempID 	!= 0x23 ||
	   pdo2.maxTempID 	!= 0x01)
	{
		tests = tests & 0xFD;
	}
	//PDO2 test end

	return tests;
}

