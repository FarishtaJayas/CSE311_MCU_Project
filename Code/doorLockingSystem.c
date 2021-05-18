#include<reg51.h>

//Setting up the keyboard

//Setting up the keypad pins 4 rows
sbit r1 = P2^0;
sbit r2 = P2^1;
sbit r3 = P2^2;
sbit r4 = P2^4;

//Setting up the keypad columns
sbit c1 = P3^0;
sbit c2 = P3^1;
sbit c3 = P3^2;

//Keyboard Setup complete

//Declaring the motor pins
sbit motp1 = P3^3;
sbit motp2 = P3^4;

//Declaring LCD connections
sbit rs = P3^5;
sbit rw = P3^6;
sbit en = P3^7;

//Declaring Red LED
sbit rled1 = P2^6;
sbit rled2 = P2^7;

//Declaring Green LED
sbit gled1 = P2^4;
sbit gled2 = P2^5;


//declaring lcd functions
void lcdcmd(unsigned char);
void lcddata(unsigned char);

//declaring string display function
void lcddis(unsigned char *q);

//declaring keypad function
char keypad();

//password checking fucntion
void check();

//delay function
void delay(unsigned int);
unsigned char pin[] = {"12345"}; // Set Password
unsigned char Epin[5];  //Entered Password 

void main()
{
		
		lcdcmd(0x0F); //LCD on command
		lcdcmd(0x38); //2 lines of the matrix
		lcdcmd(0x01);
	
		while(1)
		{
			unsigned int i = 0;
			lcdcmd(0x80);//first column of the first row of the lcd 
			gled1 = 0;
		  gled2 = 1;
			
			rled1 = 0;
		  rled2 = 1;
			
			
			lcddis("ENTER PIN..");
			delay(1000);
			lcdcmd(0xC0);
			while(pin[i] != '\0')
			{
				Epin[i] =  keypad();
				delay(1000);
				i++;
			}
			check();
		}
		
}


//Delay Function
void delay(unsigned int j) {
	int a, b;
	for(a = 0; a<j; a++) 
	{
		for(b = 0; b<10; b++);
	}
}

//LCD Command Function
void lcdcmd(unsigned char A)
{
	P1 = A;
	rs = 0;
	rw = 0;
	en = 1;
	delay(1000);
	en = 0;
}

//LCD Data Function
void lcddat(unsigned char i)
{
	P1 = i;
	rs = 1;
	rw = 0;
	en = 1;
	delay(1000);
	en = 0;
	

}
//Display Function
void lcddis(unsigned char * q)
{
	int k;
	
	//loop to display character by character on the lcd screen
	for(k = 0; q[k] != '\0'; k++)
	{
		lcddat(q[k]);	
	}  
	delay(10000);
}

//Keypad function
char keypad()
{
	int x = 0;
	while(x == 0)
	{
		r1 = 0;
		r2 = 1;
		r3 = 1;
		r4 = 1;
		
		if(c1 == 0)
		{
			lcddat('*');
			delay(100);
			x = 1;
			return '1'; //it will store the one in the array
				
		}
		if(c2 == 0)
		{
			lcddat('*');
			delay(100);
			x = 1;
			return '2';
				
		}
		if(c3 == 0)
		{
			lcddat('*');
			delay(100);
			x = 1;
			return '3';
				
		}
		
		r1 = 1; r2 = 0; r3 = 1; r4 = 1;
	
		if(c1 == 0)
		{
			lcddat('*');
			delay(100);
			x = 1;
			return '4';
				
		}
		if(c2 == 0)
		{
			lcddat('*');
			delay(100);
			x = 1;
			return '5';
				
		}
		if(c3 == 0)
		{
			lcddat('*');
			delay(100);
			x = 1;
			return '6';
				
		}
		
		r1 = 1; r2 = 1; r3 = 0; r4 = 1;
		
		if(c1 == 0)
		{
			lcddat('*');
			delay(100);
			x = 1;
			return '7';
				
		}
		if(c2 == 0)
		{
			lcddat('*');
			delay(100);
			x = 1;
			return '8';
				
		}
		
		if(c3 == 0)
		{
			lcddat('*');
			delay(100);
			x = 1;
			return '9';
				
		}
		r1 = 1; r2 = 1; r3 = 1; r4 = 0; 
		if(c1 == 0)
		{
			lcddat('*');
			delay(100);
			x = 1;
			return '*';
				
		}
		
		if(c2 == 0)
		{
			lcddat('*');
			delay(100);
			x = 1;
			return '0';
				
		}
		
		if(c3 == 0)
		{
			lcddat('*');
			delay(100);
			x = 1;
			return '#';
				
		}
			
	}
}	

//Password Check Function

void check()
{
	if(pin[0] == Epin[0] && pin[1] == Epin[1] && pin[2] == Epin[2] && pin[3] == Epin[3] && pin[4] == Epin[4]) 
	{
		
		delay(1000);
		lcdcmd(0x01);  //clear screen command
		lcdcmd(0x081); //displaying row 1, second column of the lcd
		lcddis("PIN CORRECT...");
		
		delay(1000);
		//open door mechanism with the motor
		motp1 = 1;
		motp2 = 0;
		
		lcdcmd(0xC1); //second row of the lcd
		gled1 = 1;
		gled2 = 0;
		lcddis("LOCK OPENED..");
		
		delay(1000000);
		motp1 = 1;
		motp2 = 0;
		lcdcmd(0x01); //clear screen command
	}
	else 
	{
		lcdcmd(0x01); //clear screen
		lcdcmd(0x80); //The first row of lCD
		rled1 = 1;
		rled2 = 0;
	
		lcddis("WRONG PIN..");
		
		
		delay(1000000);
		lcdcmd(0x01); // clear screen
		
	}
		
	}






