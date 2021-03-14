#ifndef __LED_H
#define __LED_H

#include "stm32l0xx_hal.h"

enum class Led_State{
	LED_ON,
	LED_OFF
};

class Led{
private:
	Led_State ledState ;
public:
	Led_State get_ledState();
	void led_turnON();
	void led_turnOFF();
	void led_toggle();
};

#endif
