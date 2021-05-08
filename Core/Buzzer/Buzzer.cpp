#ifndef __BUZZER_H_
#define __BUZZER_H_

size_t Buzzer::numOfBuzzers = 0;

Buzzer::Buzzer(){
	if(numOfBuzzers<MAX_NUMOF_BUZZERS){
		__HAL_RCC_GPIOA_CLK_ENABLE();

		GPIO_init.Mode = GPIO_MODE_OUTPUT_PP ;
		GPIO_init.Pin = GPIO_PIN_9 ;
		GPIO_init.Pull = GPIO_NOPULL ;
		HAL_GPIO_Init(GPIOA, &GPIO_init);

		HAL_GPIO_WritePin(GPIOA , GPIO_PIN_9 , GPIO_PIN_RESET );

		Buzzer::buzzerState = Buzzer_State::BUZZER_OFF ;
		Buzzer::numOfBuzzers++;
	}

}

Buzzer::~Buzzer(){
	//sleepModeInit
	numOfBuzzers--;
}

Buzzer_State Buzzer::get_ledState(){
	return Buzzer::buzzerState ;
}
void Buzzer::Buzzer_turnON(){
	Buzzer::buzzerState = Buzzer_State::BUZZER_ON ;
	HAL_GPIO_WritePin(GPIOA , GPIO_PIN_9 , GPIO_PIN_SET );
}
void Buzzer::Buzzer_turnOFF(){
	Buzzer::buzzerState = Buzzer_State::BUZZER_OFF ;
	HAL_GPIO_WritePin(GPIOA , GPIO_PIN_9 , GPIO_PIN_RESET );
}

#endif
