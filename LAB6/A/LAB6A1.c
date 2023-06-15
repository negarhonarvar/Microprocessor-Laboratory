#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

#define rs 0x01
#define rw 0x02
#define en 0x04
volatile unsigned int counter = 0;
volatile unsigned int counterIsOn = 0;
volatile unsigned int reset = 0;
volatile unsigned int isPressed = 0;
void SystemClock_Config(void);
void wait(int n) {
    volatile int i;
    for (; n > 0; n--)
        for (i = 0; i < 400; i++) ;
}
void LCD_command(unsigned char command) {
	GPIOB->ODR = 0;
    GPIOB->ODR |= command << 3;
    GPIOB->ODR |= en;
    wait(4);
    GPIOB->ODR &= ~(en);
	wait(4);
}

void LCD_data(char data) {
    GPIOB->ODR |= rs;
    GPIOB->ODR &= ~(rw);
	GPIOB->ODR &= (0B111);
    GPIOB->ODR |= data << 3;
    GPIOB->ODR |= en;
    wait(4);
    GPIOB->ODR &= ~(en);
    wait(4);
}

void LCD_init(void) {

		LCD_command(0x30);
		LCD_command(0x06);
		LCD_command(0x01);
		LCD_command(0x80);
		LCD_command(0x0C);

		LCD_data('T');
		LCD_data('I');
		LCD_data('M');
		LCD_data('E');
		LCD_data('R');
}

void display(){
				volatile unsigned int min = (counter / 10)/60;
				volatile unsigned int sec = (counter / 10)%60;
				volatile unsigned int ms = counter % 10;
				LCD_command(1);
				if(min < 10){
					LCD_data('0');
					LCD_data('0'+min);
				}else{
					LCD_data(min/10+'0');
					LCD_data(min%10+'0');
				}
				LCD_data(':');
				if(sec < 10){
					LCD_data('0');
					LCD_data('0'+sec);
				}else{
					LCD_data(sec/10+'0');
					LCD_data(sec%10+'0');
				}
				LCD_data(':');
				LCD_data(ms+'0');
				LCD_data('0');
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM3){
		counter++;
		display();
	}else if(htim->Instance == TIM2){
		reset = 1;
	}
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == KEY1_Pin){
		if(isPressed == 0){
				HAL_TIM_Base_Start_IT(&htim2);
				isPressed = 1;
		}else{
				isPressed = 0;
				if(reset == 1){
					counter = 0;
					reset = 0;
					counterIsOn = 0;
					HAL_TIM_Base_Stop(&htim3);
					HAL_TIM_Base_Stop(&htim2);
					display();

				}else{
					HAL_TIM_Base_Stop(&htim2);
					reset = 0;

					if(counterIsOn == 1){
						counterIsOn = 0;
						HAL_TIM_Base_Stop(&htim3);
					}else{
						counterIsOn = 1;
						HAL_TIM_Base_Start_IT(&htim3);
					}
				}
		}
	}
}
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_TIM3_Init();
  MX_TIM2_Init();
	LCD_init();
  while (1){}
}
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}
void Error_Handler(void)
{
  __disable_irq();
  while (1){}
}
