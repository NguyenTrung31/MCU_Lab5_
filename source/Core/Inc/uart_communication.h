/*
 * uart_communication.h
 *
 *  Created on: Dec 18, 2023
 *      Author: trung
 */

#ifndef INC_UART_COMMUNICATION_H_
#define INC_UART_COMMUNICATION_H_


#include "stdio.h"
#include "software_timer.h"
#include "command_parser.h"
#include "main.h"
#include "stm32f1xx_hal_conf.h"
#include "string.h"

void uart_communication_fsm(void);

#endif /* INC_UART_COMMUNICATION_H_ */
