#include<IRremote.h>
#include<Servo.h>

Servo baseCont;
Servo armCont;

IRrecv irrecv = 11;
decode_results results;

void setup(){
	Serial.begin(9600);
	baseCont.attach(9);
	armCont.attach(10);
	irrecv.enableIRin();
	irrecv.blink_13(true);
}

void loop(){
	if(irrecv.decode(&results)){
		Serial.print("Decoded values: ");
		Serial.println(results.value, HEX);
		switch(results.value){
			//IR HEX values
			case 0x540c:	baseCont.write(90);
			case 0x640c:    baseCont.write(0);      
		}
	}
}
