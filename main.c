#include <REGX52.H>
#include "TIMER0.h"
#include "LCD1602.h"

unsigned int CLOCK;

void main()
{
	Timer0_Init();
	LCD_Init();
	while(1)
	{
		LCD_ShowString(1,1,"clock:");
		LCD_ShowNum(2,1,CLOCK,4);
	}
}

//中断函数程序1s的跳跃
void Timer0_Routine() interrupt 1
{
	static unsigned char T0Count=0;
	TL0 = 0x66;				//设置定时初始值	TL0=64535%256;低位取余
	TH0 = 0xFC;				//设置定时初始值    TH0=64535/256;高位取商
	T0Count++;
	if(T0Count>=500)
	{
		T0Count=0;
		CLOCK++;
	}
}