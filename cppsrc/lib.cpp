#include "lib.h"

#define  ledPin    0	//define the led pin number

std::string led::ledBlink()
{	
	printf("-> CPP program is starting ... \n");
	
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
	return "LED blinked";
}

Napi::String led::ledWrapped(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();
	Napi::String res = Napi::String::New(env, led::ledBlink());

	return res;
}

Napi::Object led::Init(Napi::Env env, Napi::Object exports)
{
	exports.Set(
		"ledblink",
		Napi::Function::New(env, led::ledWrapped)
	);

	return exports;
}