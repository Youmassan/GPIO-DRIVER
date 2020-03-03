/*
 * GPIO.h
 *
 *  Created on: Feb 28, 2020
 *      Author: clt
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "stdint.h"
#include "common_macros.h"
#include "tm4c123gh6pm.h"

void SystemInit(){}

#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7
#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7
#define PC0 0
#define PC1 1
#define PC2 2
#define PC3 3
#define PC4 4
#define PC5 5
#define PC6 6
#define PC7 7
#define PD0 0
#define PD1 1
#define PD2 2
#define PD3 3
#define PD4 4
#define PD5 5
#define PD6 6
#define PD7 7
#define PE0 0
#define PE1 1
#define PE2 2
#define PE3 3
#define PE4 4
#define PE5 5
#define PF0 0
#define PF1 1
#define PF2 2
#define PF3 3
#define PF4 4


#define SET 1
#define CLEAR 0

typedef enum{
	input,//o
	outout//1
}DERICTION;


typedef enum{
	PortA,PortB,PortC,PortD,PortE,PortF
}PORT;

typedef enum{
	Digital,//o
	Analog//1
}AnaDig;


typedef struct{
	PORT Port;
	char PIN;
	AnaDig AnalogDigital;
	DERICTION Deriction;
}PIN_Config;


typedef struct{
	PORT Port;
	char PIN;
	char value;
}PinValue;


void PORT_init(PORT Port );
void PIN(const PIN_Config* Config_Ptr);
char ReadPin(const PinValue* ReadPin  );
void WritePin(const PinValue* WritePin );
void EnablePUR(const PinValue* Resistor);
void EnablePDR(const PinValue* Resistor);

#endif /* GPIO_H_ */
