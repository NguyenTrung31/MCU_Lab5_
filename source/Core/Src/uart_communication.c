/*
 * uart_communication.c
 *
 *  Created on: Dec 18, 2023
 *      Author: trung
 */


#include "uart_communication.h"

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

enum CommunicationState{Wait_RST, Send_ADC, Wait_OK};
enum CommunicationState commu_state = Wait_RST;

uint32_t ADC_value = 0;
char str[50];

void uart_communication_fsm(void){
	switch (commu_state){
	case Wait_RST:
		if (CompareCommand("RST",3) && command_flag == 1){
			command_flag = 0;
			commu_state = Send_ADC;
			ADC_value = HAL_ADC_GetValue(&hadc1);
//			HAL_UART_Transmit(&huart2 ,(void *)str , sprintf(str , "Wait RST#\r\n"), 1000);
			clerCommand();
		}
		break;
	case Send_ADC:
//		if (timer0_flag == 1){
			HAL_UART_Transmit(&huart2 ,(void *)str , sprintf(str , "\r\n!ADC=%ld#\r\n", ADC_value), 1000);
			commu_state = Wait_OK;
			setTimer0(3000);
//		}
		break;
	case Wait_OK:
		if (CompareCommand("OK",2)&& command_flag == 1 ){
//			HAL_UART_Transmit(&huart2 ,(void *)str , sprintf(str , "Wait OK#\r\n"), 1000);
			clerCommand();
			command_flag = 0;
			commu_state = Wait_RST;
			stopTimer0();
		}
		if (timer0_flag == 1){
			commu_state = Send_ADC;
			setTimer0(3000);
		}
		break;
	}
}
