#include "Led.hpp"


void Led::led_turnON(){
	GPIO_InitTypeDef GPIO_init = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_init.Mode = GPIO_MODE_OUTPUT_PP ;
	GPIO_init.Pin = GPIO_PIN_0 ;
	GPIO_init.Pull = GPIO_NOPULL ;
	HAL_GPIO_Init(GPIOA, &GPIO_init);

	ledState = Led_State::LED_ON ;

	HAL_GPIO_WritePin(GPIOA , GPIO_PIN_0 , GPIO_PIN_SET );
}

void Led::led_turnOFF(){
	GPIO_InitTypeDef GPIO_init = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_init.Mode = GPIO_MODE_OUTPUT_PP ;
	GPIO_init.Pin = GPIO_PIN_0 ;
	GPIO_init.Pull = GPIO_NOPULL ;
	HAL_GPIO_Init(GPIOA, &GPIO_init);

	ledState = Led_State::LED_OFF ;

	HAL_GPIO_WritePin(GPIOA , GPIO_PIN_0 , GPIO_PIN_RESET );
}

void Led::led_toggle(){
	GPIO_InitTypeDef GPIO_init = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_init.Mode = GPIO_MODE_OUTPUT_PP ;
	GPIO_init.Pin = GPIO_PIN_0 ;
	GPIO_init.Pull = GPIO_NOPULL ;
	HAL_GPIO_Init(GPIOA, &GPIO_init);

	if(ledState == Led_State::LED_OFF)
		ledState = Led_State::LED_ON ;
	else
		ledState = Led_State::LED_OFF ;

	HAL_GPIO_TogglePin(GPIOA , GPIO_PIN_0);
}

Led_State Led::get_ledState(){
	return ledState ;
}
