#ifndef __LED_H
#define __LED_H
#include "stm32l0xx_hal.h"

#define MAX_NUMOF_BUZZERS 1

enum class Buzzer_State{
	BUZZER_ON,
	BUZZER_OFF,
};

class Buzzer{
private:
	Buzzer_State buzzerState ;
	static size_t numOfBuzzers ;
public:
	Buzzer();
	~Buzzer();
	Buzzer_State get_ledState();
	void Buzzer_turnON();
	void Buzzer_turnOFF();
};

#endif
