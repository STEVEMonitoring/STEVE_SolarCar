/*
 * time.c
 *
 *  Created on: 29 Mar 2017
 *      Author: fredr_000
 */

uint32_t globalTimer = 0;

/**
 * @brief Increment the timer variable by 1.
 */
void incrementTime()
{
	globalTimer++;
}

/**
 * @brief Return time from startup in units of 10ms.
 */
uint32_t time()
{
	return globalTimer;
}
