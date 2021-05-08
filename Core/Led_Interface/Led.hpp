#ifndef __LED_H
#define __LED_H
#include "stm32l0xx_hal.h"


enum class Led_State{
	LED_ON,
	LED_OFF,
	LED_ERROR
};

enum class Led_Coler{
	Red_Led,
	MaxNumOfLeds
};

class Led{
private:
	Led_State ledState ;
	Led_Coler ledColer ;
	static size_t numOfLeds ;
public:
	Led(Led_Coler);
	~Led();
	Led_State get_ledState();
	void led_turnON();
	void led_turnOFF();
	void led_toggle();

};

#endif
