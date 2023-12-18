/*
 * command_parser.h
 *
 *  Created on: Dec 18, 2023
 *      Author: trung
 */

#ifndef INC_COMMAND_PARSER_H_
#define INC_COMMAND_PARSER_H_

#include "stdio.h"
#include "string.h"
#define MAX_BUFFER_SIZE 30

extern uint8_t temp;
extern uint8_t index_buffer;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern int command_flag;


void command_parser_fsm(void);
unsigned char  CompareCommand(char resp[],size_t num);
void clerCommand(void);



#endif /* INC_COMMAND_PARSER_H_ */
