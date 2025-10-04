#include "bsp.h"
#include "stdio.h"

// LED显示当前运行状态，每10毫秒调用一次，LED灯每200毫秒闪烁一次。
// The LED displays the current operating status, which is invoked every 10 milliseconds, and the LED blinks every 200 milliseconds.  
void Bsp_Led_Show_State_Handle(void)
{
	static uint8_t led_count = 0;
	led_count++;
	if (led_count > 20)
	{
		led_count = 0;
		LED_TOGGLE();
	}
}


// The peripheral device is initialized  外设设备初始化
void Bsp_Init(void)
{
	HAL_Delay(100);
	char text[] = "Hello Yahboom";
	SSD1306_Init();
	OLED_Draw_Line(text, 1, 1, 1);

	HAL_UART_Transmit(&huart1, (uint8_t*)text, sizeof(text), 1000);
	Beep_On_Time(50);
}


// main.c中循环调用此函数，避免多次修改main.c文件。
// This function is called in a loop in main.c to avoid multiple modifications to the main.c file
void Bsp_Loop(void)
{
	// Detect button down events   检测按键按下事件
	if (Key1_State(KEY_MODE_ONE_TIME))
	{
		static int count = 0;
		count++;
		char line_one[] = "Hello Yahboom";
		char line_two[] = "Press KEY1";
		char line_three[10];
		sprintf(line_three, "%d", count);
		OLED_Draw_Line(line_one, 1, 1, 0);
		OLED_Draw_Line(line_two, 2, 0, 0);
		OLED_Draw_Line(line_three, 3, 0, 1);

		Beep_On_Time(50);
	}

	Bsp_Led_Show_State_Handle();
	// The buzzer automatically shuts down when times out   蜂鸣器超时自动关闭
	Beep_Timeout_Close_Handle();
	HAL_Delay(10);
}
