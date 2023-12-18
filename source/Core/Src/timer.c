/*
 * timer.c
 *
 *  Created on: Dec 18, 2023
 *      Author: trung
 */


#include <software_timer.h>
#include "main.h"

void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	if(htim->Instance == TIM2 ){
		timerRun();
	}
}
