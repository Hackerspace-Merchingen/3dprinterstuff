#include <avr/io.h>
#include <util/delay.h>

// Creality 1.1.4 Stepper_X
#define	stepPin PD7            //Define Step pin
#define stepPin_PORT PORTD
#define stepPin_DDR DDRD
#define dirPin PC5             //Define Direction pin
#define dirPin_PORT PORTC
#define dirPin_DDR DDRC
#define enablePin PD6          //Define Enable pin
#define enablePin_PORT PORTD
#define enablePin_DDR DDRD
#define controlSwitch PC2      //Define Control Switch pin (D2)
#define controlSwitch_PORT PORTC
#define controlSwitch_DDR DDRC
#define controlSwitch_PIN PINC
#define beeper PA4             // Define beeper pin (D4)
#define beeper_PORT PORTA
#define beeper_DDR DDRA
#define klipper PA3             // Define Klipper connector pin (LCS_CS)
#define klipper_PORT PORTA
#define klipper_DDR DDRA

int main(void)
{
									     // Configure ports as output
    stepPin_DDR |= (1<<stepPin);	 
	dirPin_DDR |= (1<<dirPin);	 
	enablePin_DDR |= (1<<enablePin);	 
	beeper_DDR |= (1<<beeper);	 
	klipper_DDR |= (1<<klipper);	 
	
	beeper_PORT |= (1<<beeper); // disable beeper
	
									     // Configure ports as input	
	controlSwitch_DDR &= ~(1 << controlSwitch);
	
	                                     // activate internal pullups
	controlSwitch_PORT |= (1 << controlSwitch);    
	
	
    enablePin_PORT &= ~(1<<enablePin);   // Enable driver
	dirPin_PORT &= ~(1<<dirPin);         //Make PORTA6 low to rotate motor in reverse clockwise direction
	
    klipper_PORT &= ~(1<<klipper);       // disable klipper emergency
	
	int i=0;
	int switch_continuous_count=0;
	
    while (switch_continuous_count<2) 
    {
		if (!(controlSwitch_PIN & (1<<controlSwitch)) == 1) //If switch is pressed, but not stuck
           {
		      if(switch_continuous_count>0)
			  {
			     switch_continuous_count++;
			  }
			  else
			  {
			     switch_continuous_count=1;
			  }
		   
		   	  enablePin_PORT &= ~(1<<enablePin);

		      for(i=0;i<5000;i++)
			     {
				  	switch (i)
					{
						case 1 ... 100:
							step(20,80);
							break;
						case 101 ... 500:
							step(10,40);
							break;
						case 501 ... 5000:
							step(10,30);
							break;
					}
				 }
		   }
		else
		   {
		      enablePin_PORT |= (1<<enablePin);
			  switch_continuous_count=0;
		   }
    }
	
	klipper_PORT |= (1<<klipper);       // enable klipper emergency

}

void step(uint8_t active_us, uint8_t inactive_us)
{
	int us=0;
	stepPin_PORT |=(1<<stepPin);
	for (us=0;us<active_us;us++) { _delay_us(1); }
	stepPin_PORT &=~(1<<stepPin);
	for (us=0;us<inactive_us;us++) { _delay_us(1); }
}