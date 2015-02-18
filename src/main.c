//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_gpio.h>

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

int main(int argc, char* argv[]) {
	__GPIOG_CLK_ENABLE();

	GPIO_InitTypeDef gpio;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pin = GPIO_PIN_11;
	gpio.Speed = GPIO_SPEED_LOW;
	gpio.Pull = GPIO_NOPULL;

	// Blink PG11
	HAL_GPIO_Init(GPIOG, &gpio);
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_11, DISABLE);

	// Infinite loop
	while (1) {
		HAL_Delay(300);
		HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_11);
	}
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
