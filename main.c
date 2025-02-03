#include <REGX52.H>
#include "LCD1602.h"
#include "TIMER0.h"

unsigned char SEC=0;

void main()
{
	LCD_Init();
	Timer0_Init();
	LCD_ShowString(1,1,"CLOCK:");
	while(1)
	{
		LCD_ShowNum(2,1,SEC,2);
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
		SEC++;
//		if(SEC>=99) SEC=0;
	}
}
