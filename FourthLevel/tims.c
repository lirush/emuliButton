#include "tims.h"
#include <MDR32F9Qx_rst_clk.h>
#include <MDR32F9Qx_port.h>
#include <MDR32F9Qx_timer.h>

volatile uint16_t timeslots =0;

void Timer1_IRQHandler(void)
{
	if(MDR_TIMER1->STATUS & (1<<1 ))
	{
        timeslots++;			
        MDR_TIMER1->STATUS =0;
	}
}

void xTimer2Init(void)
{
	PORT_InitTypeDef PortInitStructure;
	
	MDR_RST_CLK->PER_CLOCK |= (1<<24);																	//Enable clock port D

	PortInitStructure.PORT_Pin = PORT_Pin_5;
	PortInitStructure.PORT_OE		= PORT_OE_IN;
	PortInitStructure.PORT_FUNC = PORT_FUNC_OVERRID;
	PortInitStructure.PORT_PULL_DOWN = PORT_PULL_DOWN_ON;
	PortInitStructure.PORT_MODE = PORT_MODE_DIGITAL;
	PortInitStructure.PORT_SPEED = PORT_SPEED_FAST;
	PORT_Init(MDR_PORTD, &PortInitStructure);

	RST_CLK_PCLKcmd(RST_CLK_PCLK_TIMER2,ENABLE);

	MDR_TIMER2->CNTRL = 0;
	MDR_RST_CLK->TIM_CLOCK |= ((0 << RST_CLK_TIM_CLOCK_TIM2_BRG_Pos)
			| (1 << RST_CLK_TIM_CLOCK_TIM2_CLK_EN_Pos));

	MDR_TIMER2->BRKETR_CNTRL |= (0<<4|0<<2);

	MDR_TIMER2->IE = (1<<3) | (1<<2) ;																									//IE fall

	MDR_TIMER2->CNTRL = (8<<TIMER_CNTRL_EVENT_SEL_Pos) | (1<<TIMER_CNTRL_CNT_EN_Pos);		 //ETR mode 2, enable timer

	NVIC_EnableIRQ(Timer2_IRQn);

}

/*
T=10ms.
*/
void xTimer1Init(void)
{
    
    RST_CLK_PCLKcmd(RST_CLK_PCLK_TIMER1,ENABLE);                                
    TIMER_BRGInit(MDR_TIMER1,TIMER_HCLKdiv1);                                   
    
    TIMER_DeInit(MDR_TIMER1);
    
		MDR_TIMER1->CNT = 0x00;
		MDR_TIMER1->PSG = 0x03E8;
		MDR_TIMER1->ARR = 0x0320;
		
		MDR_TIMER1->CNTRL = (0<<6) | (0<<8) | (0<<4) | (0<<1);   
	
		MDR_TIMER1->IE = (1<<1);
  
		MDR_TIMER1->CNTRL |= (1<<0);
    
    NVIC_EnableIRQ(Timer1_IRQn);
}
