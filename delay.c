void LCD_Delay()	//@11.0592MHz
{
	unsigned char data i, j;
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}