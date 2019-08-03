/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 ******************************************************************************
 *test
 *
 *
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define SA_ON HAL_GPIO_WritePin(SA_GPIO_Port, SA_Pin, 0)
#define SB_ON HAL_GPIO_WritePin(SB_GPIO_Port, SB_Pin, 0)
#define SC_ON HAL_GPIO_WritePin(SC_GPIO_Port, SC_Pin, 0)
#define SD_ON HAL_GPIO_WritePin(SD_GPIO_Port, SD_Pin, 0)
#define SE_ON HAL_GPIO_WritePin(SE_GPIO_Port, SE_Pin, 0)
#define SF_ON HAL_GPIO_WritePin(SF_GPIO_Port, SF_Pin, 0)
#define SG_ON HAL_GPIO_WritePin(SG_GPIO_Port, SG_Pin, 0)

#define SA_OFF HAL_GPIO_WritePin(SA_GPIO_Port, SA_Pin, 1)
#define SB_OFF HAL_GPIO_WritePin(SB_GPIO_Port, SB_Pin, 1)
#define SC_OFF HAL_GPIO_WritePin(SC_GPIO_Port, SC_Pin, 1)
#define SD_OFF HAL_GPIO_WritePin(SD_GPIO_Port, SD_Pin, 1)
#define SE_OFF HAL_GPIO_WritePin(SE_GPIO_Port, SE_Pin, 1)
#define SF_OFF HAL_GPIO_WritePin(SF_GPIO_Port, SF_Pin, 1)
#define SG_OFF HAL_GPIO_WritePin(SG_GPIO_Port, SG_Pin, 1)

//digits. We have 4, from 1 to 4. Digits are anodes, so you can turn it on by pulling
//to supply voltage
#define D1_ON HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, 1)
#define D2_ON HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, 1)
#define D3_ON HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, 1)
#define D4_ON HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, 1)

#define D1_OFF HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, 0)
#define D2_OFF HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, 0)
#define D3_OFF HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, 0)
#define D4_OFF HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, 0)

//turning off
#define D_OFF D1_OFF; D2_OFF; D3_OFF; D4_OFF
#define S_OFF SA_OFF; SB_OFF; SC_OFF; SD_OFF; SE_OFF; SF_OFF; SG_OFF
#define ALL_OFF D_OFF; S_OFF

//display delay
#define WAIT HAL_Delay(1)

//buttons
#define CLEAR HAL_GPIO_ReadPin(CLEAR_GPIO_Port, CLEAR_Pin) == 0
#define SET HAL_GPIO_ReadPin(SET_GPIO_Port, SET_Pin) == 0

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc;

TIM_HandleTypeDef htim14;

/* USER CODE BEGIN PV */
float reading;
float temp = 0;
float vsense;
float buffer[20];
int counter;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC_Init(void);
static void MX_TIM14_Init(void);
/* USER CODE BEGIN PFP */
void display(int position, int number);
void display_twice(int position, int number);

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (buffer[0] > temp && buffer[1] > temp && buffer[2] > temp
			&& buffer[3] > temp && buffer[4] > temp && buffer[5] > temp
			&& buffer[6] > temp && buffer[7] > temp && buffer[8] > temp
			&& buffer[9] > temp && buffer[10] > temp && buffer[11] > temp
			&& buffer[12] > temp && buffer[13] > temp && buffer[14] > temp
			&& buffer[15] > temp && buffer[16] > temp && buffer[17] > temp
			&& buffer[18] > temp && buffer[19] > temp) {
		temp++;
	} else if (buffer[0] < temp && buffer[1] < temp && buffer[2] < temp
			&& buffer[3] < temp && buffer[4] < temp && buffer[5] < temp
			&& buffer[6] < temp && buffer[7] < temp && buffer[8] < temp
			&& buffer[9] < temp && buffer[10] < temp && buffer[11] < temp
			&& buffer[12] < temp && buffer[13] < temp && buffer[14] < temp
			&& buffer[15] < temp && buffer[16] < temp && buffer[17] < temp
			&& buffer[18] < temp && buffer[19] < temp) {
		temp--;
	}

}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_ADC_Init();
	MX_TIM14_Init();
	/* USER CODE BEGIN 2 */
	HAL_ADC_Start(&hadc);
	HAL_TIM_Base_Start_IT(&htim14);
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {

		if (HAL_ADC_PollForConversion(&hadc, 100) == HAL_OK) {

			reading = HAL_ADC_GetValue(&hadc);
			HAL_ADC_Start(&hadc);

			vsense = (reading * 3.3) / 1023;

			//temp = vsense * 100;
			buffer[counter] = vsense * 100;
			counter++;
			if (counter > 20)
				counter = 0;

		}

//		vsense = (reading / 4095) * 3.3;
//		temp = ((v30 - vsense) / avgSlope) + 30;

//		vsense = (reading * 2.5) / 4095;
//		temp = vsense * 100;

		display_twice(1, temp);
		display(3, 10); //degree
		display(4, 11); //Celsius

		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/** Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI
			| RCC_OSCILLATORTYPE_HSI14;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSI14State = RCC_HSI14_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.HSI14CalibrationValue = 16;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief ADC Initialization Function
 * @param None
 * @retval None
 */
static void MX_ADC_Init(void) {

	/* USER CODE BEGIN ADC_Init 0 */

	/* USER CODE END ADC_Init 0 */

	ADC_ChannelConfTypeDef sConfig = { 0 };

	/* USER CODE BEGIN ADC_Init 1 */

	/* USER CODE END ADC_Init 1 */
	/** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
	 */
	hadc.Instance = ADC1;
	hadc.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
	hadc.Init.Resolution = ADC_RESOLUTION_10B;
	hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	hadc.Init.ScanConvMode = ADC_SCAN_DIRECTION_FORWARD;
	hadc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	hadc.Init.LowPowerAutoWait = DISABLE;
	hadc.Init.LowPowerAutoPowerOff = DISABLE;
	hadc.Init.ContinuousConvMode = DISABLE;
	hadc.Init.DiscontinuousConvMode = DISABLE;
	hadc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	hadc.Init.DMAContinuousRequests = DISABLE;
	hadc.Init.Overrun = ADC_OVR_DATA_PRESERVED;
	if (HAL_ADC_Init(&hadc) != HAL_OK) {
		Error_Handler();
	}
	/** Configure for the selected ADC regular channel to be converted.
	 */
	sConfig.Channel = ADC_CHANNEL_7;
	sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
	sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
	if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN ADC_Init 2 */

	/* USER CODE END ADC_Init 2 */

}

/**
 * @brief TIM14 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM14_Init(void) {

	/* USER CODE BEGIN TIM14_Init 0 */

	/* USER CODE END TIM14_Init 0 */

	/* USER CODE BEGIN TIM14_Init 1 */

	/* USER CODE END TIM14_Init 1 */
	htim14.Instance = TIM14;
	htim14.Init.Prescaler = 899;
	htim14.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim14.Init.Period = 899;
	htim14.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim14.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim14) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN TIM14_Init 2 */

	/* USER CODE END TIM14_Init 2 */

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOF, SF_Pin | SE_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA,
			D4_Pin | D3_Pin | D2_Pin | D1_Pin | SG_Pin | SA_Pin | SB_Pin
					| SD_Pin | SC_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pins : SF_Pin SE_Pin */
	GPIO_InitStruct.Pin = SF_Pin | SE_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

	/*Configure GPIO pins : D4_Pin D3_Pin D2_Pin D1_Pin
	 SG_Pin SA_Pin SB_Pin SD_Pin
	 SC_Pin */
	GPIO_InitStruct.Pin = D4_Pin | D3_Pin | D2_Pin | D1_Pin | SG_Pin | SA_Pin
			| SB_Pin | SD_Pin | SC_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void display(int position, int number) {
	ALL_OFF
	;
	int ok = 1;
	switch (position) {
	case 1:
		D1_ON;
		break;
	case 2:
		D2_ON;
		break;
	case 3:
		D3_ON;
		break;
	case 4:
		D4_ON;
		break;
	default:
		ok = 0;		//secure. Dont turn LEDs, if position is different than 1-4
	}
	if (ok == 1) {
		switch (number) {
		case 0:
			SA_ON;
			SB_ON;
			SC_ON;
			SD_ON;
			SE_ON;
			SF_ON;
			break;
		case 1:
			SB_ON;
			SC_ON;
			break;
		case 2:
			SA_ON;
			SB_ON;
			SG_ON;
			SE_ON;
			SD_ON;
			break;
		case 3:
			SA_ON;
			SB_ON;
			SG_ON;
			SC_ON;
			SD_ON;
			break;

		case 4:
			SB_ON;
			SG_ON;
			SF_ON;
			SC_ON;
			break;
		case 5:
			SA_ON;
			SF_ON;
			SG_ON;
			SC_ON;
			SD_ON;
			break;

		case 6:
			SA_ON;
			SF_ON;
			SG_ON;
			SC_ON;
			SE_ON;
			SD_ON;
			break;

		case 7:
			SA_ON;
			SB_ON;
			SC_ON;
			break;

		case 8:
			SA_ON;
			SB_ON;
			SC_ON;
			SD_ON;
			SE_ON;
			SF_ON;
			SG_ON;
			break;

		case 9:
			SA_ON;
			SB_ON;
			SC_ON;
			SD_ON;
			SG_ON;
			SF_ON;
			break;

		case 10:		//degree
			SA_ON;
			SB_ON;
			SG_ON;
			SF_ON;
			break;

		case 11:		//C letter

			SA_ON;
			SF_ON;
			SE_ON;
			SD_ON;
			break;

		}
	}
	WAIT;
	ALL_OFF
	;
}

void display_twice(int position, int number) {
	int first_digit;
	int second_digit;
	ALL_OFF
	;
//brake a number into two digits
	if (number <= 9) {
		first_digit = 0;
		second_digit = number;
	}
	if ((number >= 10) && (number <= 19)) {		//check if number is from range
		first_digit = 1;
		second_digit = number - 10;
	}
	if ((number >= 20) && (number <= 29)) {		//check if number is from range
		first_digit = 2;
		second_digit = number - 20;
	}
	if ((number >= 30) && (number <= 39)) {		//check if number is from range
		first_digit = 3;
		second_digit = number - 30;
	}
	if ((number >= 40) && (number <= 49)) {		//check if number is from range
		first_digit = 4;
		second_digit = number - 40;
	}
	if ((number >= 50) && (number <= 59)) {		//check if number is from range
		first_digit = 5;
		second_digit = number - 50;
	}
	if ((number >= 60) && (number <= 69)) {		//check if number is from range
		first_digit = 6;
		second_digit = number - 60;
	}
	if ((number >= 70) && (number <= 79)) {		//check if number is from range
		first_digit = 7;
		second_digit = number - 70;
	}
	if ((number >= 80) && (number <= 89)) {		//check if number is from range
		first_digit = 8;
		second_digit = number - 80;
	}
	if ((number >= 90) && (number <= 99)) {		//check if number is from range
		first_digit = 8;
		second_digit = number - 90;
	}

	display(position, first_digit);
	display(position + 1, second_digit);

}
/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */

	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(char *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
	 tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
