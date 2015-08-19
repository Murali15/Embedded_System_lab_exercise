# Embedded_System_lab_exercise
#include<reg51.h>
sbit mybit=P2^0;

sbit seg1=P0^1;
sbit seg2=P0^2;
sbit seg3=P0^3;
sbit seg4=P0^4;

void delay()
{
	int i,j;
	for(i=0;i<10;i++)
	for(j=0;j<1724;j++);

}

void ext1() interrupt 0  // ex0 and ex2 are external interrupt
{
	
	int arr[]={0x06,0x54,0x78,0x3F}; //this is for int 0,here 0x06=I,IT CONTINUES ...
mybit=~mybit;
	seg1=1;seg2=0;seg3=0;seg4=0;P1=arr[0];delay(); //ANY ONE SEGMENT SHOULD BE IN 'on' condition
	seg1=0;seg2=1;seg3=0;seg4=0;P1=arr[1];delay();
	seg1=0;seg2=0;seg3=1;seg4=0;P1=arr[2];delay();
	seg1=0;seg2=0;seg3=0;seg4=1;P1=arr[3];delay();  //this is for '0'
}

void ext2() interrupt 2
{
	
	int arr[]={0x06,0x54,0x78,0x06};
mybit=~mybit;

	seg1=1;seg2=0;seg3=0;seg4=0;P1=arr[0];delay();
	seg1=0;seg2=1;seg3=0;seg4=0;P1=arr[1];delay();
	seg1=0;seg2=0;seg3=1;seg4=0;P1=arr[2];delay();
	seg1=0;seg2=0;seg3=0;seg4=1;P1=arr[3];delay();
}

void timerint1() interrupt 1
{

int arr[]={0x06,0x54,0x78,0x06}; //this is for int 0,here 0x06=I,IT CONTINUES ...
mybit=~mybit;
seg1=1;seg2=0;seg3=0;seg4=0;P1=arr[0];delay(); //ANY ONE SEGMENT SHOULD BE IN 'on' condition
seg1=0;seg2=1;seg3=0;seg4=0;P1=arr[1];delay();
seg1=0;seg2=0;seg3=1;seg4=0;P1=arr[2];delay();
seg1=0;seg2=0;seg3=0;seg4=1;P1=arr[3];delay();  //this is for '0'


TR0=0;


//TR1=1;
}

void timerint2() interrupt 3
{
	
int arr[]={0x06,0x54,0x78,0x4F};
mybit=~mybit;
	seg1=1;seg2=0;seg3=0;seg4=0;P1=arr[0];delay();
	seg1=0;seg2=1;seg3=0;seg4=0;P1=arr[1];delay();
	seg1=0;seg2=0;seg3=1;seg4=0;P1=arr[2];delay();
	seg1=0;seg2=0;seg3=0;seg4=1;P1=arr[3];delay();

TR1=0;

//TR0=1;
}



void main()
{
	IE=0x8F;
	TMOD=0X11;
	TH0=0X4B;
	TL0=0XFC;
	TL1=0X1C;
TH1=0X1B;TR0=1;
TR1=1;
	
	while(1);
}
