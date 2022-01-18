#include "lib.h"

#define  ledPin    0	//define the led pin number

void ledBlink()
{	
	printf("CPP program is starting ... \n");
	
	wiringPiSetup();	//Initialize wiringPi.
	
	pinMode(ledPin, OUTPUT);//Set the pin mode
	printf("Using pin%d\n", ledPin);	//Output information on terminal
	while(1){
		digitalWrite(ledPin, HIGH);  //Make GPIO output HIGH level
		printf("led turned on >>>\n");		//Output information on terminal
		delay(1000);						//Wait for 1 second
		digitalWrite(ledPin, LOW);  //Make GPIO output LOW level
		printf("led turned off <<<\n");		//Output information on terminal
		delay(1000);						//Wait for 1 second
	}
}
