/*
***Develop by the team AO NPP AME 06.2021
***
***This software is an emulater key iButton.
***This programm is for Milander microcontroller only series 1986VE9x
***Settings clock to be in SystemInit. (80 MHz)
***
***This eiButton can use as iButton, but you can not write certificate to eiButton.

*** Разработано коллективом АО НПП ВМЭ 06.2021 г.
***
*** Данная программа представляет собой эмулятор ключа iButton.
*** Эта программа предназначена только для микроконтроллеров Milander серии 1986VE9x.
*** Настройки часов должны быть в SystemInit. (80 МГц)
***
*** Этот eiButton можно использовать как iButton, но вы не можете записать сертификат в eiButton.
*/
#include <stdint.h>
#include "MDR32F9Qx_rst_clk.h"
#include "MDR32F9Qx_port.h"
#include <MDR32F9Qx_eeprom.h>

#include "main.h"
#include "uart.h"

void xPortInit(void)
{
  PORT_InitTypeDef PortInitStructure;
	
	MDR_RST_CLK->PER_CLOCK |= (1<<21);

/************************ Digital Output *************************/    
/* Configure PORTA pins 3..5 for output*/
  PortInitStructure.PORT_Pin = PORT_Pin_0 | PORT_Pin_1;
  PortInitStructure.PORT_OE    = PORT_OE_OUT;
  PortInitStructure.PORT_FUNC = PORT_FUNC_PORT;
  PortInitStructure.PORT_MODE = PORT_MODE_DIGITAL;
  PortInitStructure.PORT_SPEED = PORT_SPEED_FAST;
	PortInitStructure.PORT_GFEN = PORT_GFEN_ON;
  
  PORT_Init(MDR_PORTA, &PortInitStructure);	
}

uint8_t cnt_s4=0,b=0x01;
int main(void)
{
	xPortInit();
	xSetPoint(30.0);																										//step SysTicks =30us											
	MDR_PORTA->RXTX |= (1<<1) | (1<<0);
	xTimer2Init();
	while(1)
	{

	}
	
}
