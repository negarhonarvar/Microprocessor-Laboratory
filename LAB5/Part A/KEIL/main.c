#include "stm32f4xx_hal.h"

// Define GPIO pin for LED
#define LED_PIN GPIO_PIN_13
#define LED_PORT GPIOG

// Define GPIO pins for buttons
#define INC_BTN_PIN GPIO_PIN_0
#define INC_BTN_PORT GPIOA

#define DEC_BTN_PIN GPIO_PIN_1
#define DEC_BTN_PORT GPIOA

// Function prototypes
void SystemClock_Config(void);
void GPIO_Init(void);

// Global variables
uint32_t brightness = 0;

int main(void)
{
    // Initialize HAL library
    HAL_Init();

    // Configure the system clock
    SystemClock_Config();

    // Initialize GPIOs for LED and buttons
    GPIO_Init();

    // Infinite loop
    while (1)
    {
        // Check if the increment button is pressed
        if (HAL_GPIO_ReadPin(INC_BTN_PORT, INC_BTN_PIN) == GPIO_PIN_RESET)
        {
            // Increase brightness
            brightness += 10;
            if (brightness > 100)
                brightness = 100;
        }

        // Check if the decrement button is pressed
        if (HAL_GPIO_ReadPin(DEC_BTN_PORT, DEC_BTN_PIN) == GPIO_PIN_RESET)
        {
            // Decrease brightness
            brightness -= 10;
            if (brightness < 0)
                brightness = 0;
        }

        // Set LED brightness based on the global variable
        __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, brightness);

        // Delay for debouncing (adjust as needed)
        HAL_Delay(50);
    }
}

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLM = 8;
    RCC_OscInitStruct.PLL.PLLN = 168;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 4;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
                                  RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
    {
        Error_Handler();
    }
}

void GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Enable GPIO clocks
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();

    // Configure LED pin as output
    GPIO_InitStruct.Pin = LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;  // Connect LED pin to TIM2
    HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);

    // Configure increment button pin as input with pull-up
    GPIO_InitStruct.Pin = INC_BTN_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(INC_BTN_PORT, &GPIO_InitStruct);

    // Configure decrement button pin as input with pull-up
    GPIO_InitStruct.Pin = DEC_BTN_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(DEC_BTN_PORT, &GPIO_InitStruct);
  }