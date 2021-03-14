#ifndef __TIMER_H
#define __TIMER_H

#include "main.h"

typedef enum {
	microsec,
	millisec
}delay_type_t;

class Delay{
private:
	TIM_HandleTypeDef htim2;
	void (* timer_interrupt_service)(void) = nullptr;
	void initTimerStructBasic(TIM_HandleTypeDef *htim , uint32_t period, delay_type_t delay_type);
	void prescaler_period_calc(uint32_t* time , uint32_t* prescaler);

public:
	void Delay_ms_NonBlock(uint32_t time);
	void Delay_ms_Block(uint32_t time);
	void Delay_us_NonBlock(uint32_t time);
	void Delay_us_Block(uint32_t time);
};

#endif
