#include <Led.hpp>

size_t Led::numOfLeds = 0 ;
/*
 * if the user instantiate two LEDs with the same coler it could leads to runtime undefined behavior
 * so it must be some guard to prevent such a case
 */
Led::Led(Led_Coler coler):ledColer{coler}{
	if(Led::numOfLeds < static_cast<size_t>(Led_Coler::MaxNumOfLeds) /* || led is already instantiated */){
		GPIO_InitTypeDef GPIO_init = {0};

		if(ledColer == Led_Coler::Red_Led){
			__HAL_RCC_GPIOA_CLK_ENABLE();

			GPIO_init.Mode = GPIO_MODE_OUTPUT_PP ;
			GPIO_init.Pin = GPIO_PIN_0 ;
			GPIO_init.Pull = GPIO_NOPULL ;
			HAL_GPIO_Init(GPIOA, &GPIO_init);

			ledState = Led_State::LED_OFF ;
			HAL_GPIO_WritePin(GPIOA , GPIO_PIN_0 , GPIO_PIN_RESET );

			Led::numOfLeds++;
		}
	}
	else{
		ledState = Led_State::LED_ERROR ;
	}
}

Led::~Led(){
	//sleepModeInit
	numOfLeds--;
}

void Led::led_turnON(){

	Led::ledState = Led_State::LED_ON ;
	HAL_GPIO_WritePin(GPIOA , GPIO_PIN_0 , GPIO_PIN_SET );
}

void Led::led_turnOFF(){
	Led::ledState = Led_State::LED_OFF ;
	HAL_GPIO_WritePin(GPIOA , GPIO_PIN_0 , GPIO_PIN_RESET );
}

void Led::led_toggle(){
	if(ledState == Led_State::LED_OFF)
		ledState = Led_State::LED_ON ;
	else
		ledState = Led_State::LED_OFF ;

	HAL_GPIO_TogglePin(GPIOA , GPIO_PIN_0);
}

Led_State Led::get_ledState(){
	return ledState ;
}
