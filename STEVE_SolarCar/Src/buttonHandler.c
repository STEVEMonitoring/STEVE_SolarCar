/*
 * buttonHandler.c
 *
 *  Created on: 31 Mar 2017
 *      Author: fredr_000
 */
#include "stdint.h"
#include "buttonHandler.h"
#include "time.h"
#include "stm32l4xx_hal.h"
#include "main.h"

/* Global variables */
int8_t buttonEvent = 0;


/**
 * Set a variable to 1 (button has been pushed)
 */
void buttonTrigger()
{
	buttonEvent = 1;
}


/**
 * Deals with the button event
 */
void buttonEventHandler()
{
	  if(buttonEvent == 1)
	  {
		  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);

		  buttonEvent = 0;
	  }
}
