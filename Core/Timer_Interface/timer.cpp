#include "timer.hpp"




void Delay::Delay_ms_NonBlock(uint32_t time){
	  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	  TIM_MasterConfigTypeDef sMasterConfig = {0};

	  initTimerStructBasic(&htim2, time , millisec);
	  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
	  {
	    Error_Handler();
	  }

	  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }

	  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  HAL_TIM_Base_Start(&htim2);
}


void Delay::Delay_ms_Block(uint32_t time){
	  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	  TIM_MasterConfigTypeDef sMasterConfig = {0};
	  initTimerStructBasic(&htim2, time , millisec);
	  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }

	  //user
	  HAL_TIM_Base_Start(&htim2);
	  while(! __HAL_TIM_GET_FLAG(&htim2, TIM_FLAG_UPDATE)) ;
	  __HAL_TIM_CLEAR_FLAG(&htim2, TIM_FLAG_UPDATE);
	  //end user
	  HAL_TIM_Base_DeInit(&htim2);
}


void Delay::Delay_us_NonBlock(uint32_t time){
	  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	  TIM_MasterConfigTypeDef sMasterConfig = {0};
	  initTimerStructBasic(&htim2, time , microsec);
	  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  HAL_TIM_Base_Start(&htim2);

}


void Delay::Delay_us_Block(uint32_t time){
	  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
	  TIM_MasterConfigTypeDef sMasterConfig = {0};

	  initTimerStructBasic(&htim2, time, microsec);
	  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }

	  //user
	  HAL_TIM_Base_Start(&htim2);
	  while(! __HAL_TIM_GET_FLAG(&htim2, TIM_FLAG_UPDATE)) ;
	  __HAL_TIM_CLEAR_FLAG(&htim2, TIM_FLAG_UPDATE);
	  HAL_TIM_Base_Stop(&htim2);
	  //end user
	  HAL_TIM_Base_DeInit(&htim2);
}


void Delay:: initTimerStructBasic(TIM_HandleTypeDef *htim , uint32_t delay, delay_type_t delay_type){
	  SystemCoreClockUpdate();
	  uint32_t prescaler = 0 ;

	  switch (delay_type){
	  case microsec:
		  prescaler = SystemCoreClock/1000000 ; //   counts/1microsec
		  break;
	  case millisec:
		  prescaler = SystemCoreClock/1000 ;    //   counts/1millisec
		  break;

      default:
    	  prescaler = 0;
    	  break;
	  }

	  prescaler_period_calc(&delay,&prescaler);
	  htim2.Init.Prescaler = prescaler;
	  htim2.Init.Period = delay;
	  htim2.Instance = TIM2;
	  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
	  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
}

void Delay:: prescaler_period_calc(uint32_t* time , uint32_t* prescaler){
	while((uint32_t)0xFFFF > *time){
		*time/=2 ;
		*prescaler*=2 ;
	}
}
