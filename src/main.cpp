#include <Arduino.h>
/*		Placa NODEMCU
* 	0	-> 	D3
* 	1	-> 	TX
* 	2	-> 	D4
* 	3	-> 	RX
* 	4	-> 	D2
* 	5	-> 	D1
* 	12	-> 	D6
* 	13	-> 	D7
* 	14	-> 	D5
* 	14	-> 	D8
* 	16	-> 	D0
*/

#define LedVerde 5 //D1
#define LedVermelho 4 //D2
#define LedAmarelo 0 //D3

void setup() {
  	// put your setup code here, to run once:
	pinMode(LedVerde, OUTPUT);
	pinMode(LedVermelho, OUTPUT);
	pinMode(LedAmarelo, OUTPUT);
}

void loop() {
	// put your main code here, to run repeatedly:
	digitalWrite(LedVerde, HIGH);
	delay(1000);
	digitalWrite(LedVermelho, HIGH);
	delay(1000);
	digitalWrite(LedAmarelo, HIGH);
	delay(1000);
	digitalWrite(LedAmarelo, LOW);
	delay(1000);
	digitalWrite(LedVermelho, LOW);
	delay(1000);
	digitalWrite(LedVerde, LOW);
	delay(1000);
}