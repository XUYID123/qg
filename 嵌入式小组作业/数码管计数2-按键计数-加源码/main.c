#include <REG51.H>
unsigned char number;
unsigned char num[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char shuzi[]={0,0};
unsigned char weishu[]={0x80,0x40};
unsigned char Key;
void Delay(unsigned int xms)   
	{
		unsigned char i;
		while(xms--)
		{
			for(i=0;i<125;i++){};
		}
	}
	
void Show()
{
	unsigned char f;
	shuzi[0]=number/10;
	shuzi[1]=number%10;
	for(f=0;f<2;f++)
  {
	  P2=weishu[f];
		P3=num[shuzi[f]];
	  Delay(10);
	}
}
void main()
{
    unsigned char w=0;
	  P1=0xff;
	  Key=P1;
		while(1)
		{
			Show();
			Key=P1;
			if(Key!=0xff)
			{
				for(w=0;w<15;w++) 
				{
					Show();
				}
			}
			if(Key==0xfe)
			{ 
				if(number<99) number++;
				else number=0;
			}
			if(Key==0xfd)
			{
				if(number>0) number--;
				else number=99;
			}
		}
}