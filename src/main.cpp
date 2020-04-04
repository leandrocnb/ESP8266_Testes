#include <Arduino.h>
#include "ACS712.h"
 
// Estou usando ACS de 30A. Mude para o modelo que está usando. Valores possíveis: 5,20 e 30
// Sensor ligado na porta analópgica A0
ACS712 sensor(ACS712_30A, A0);
 
void setup() {
  // É necessário calibrar o sensor antes de usar a primeira vez com o método abaixo
  Serial.begin(9600);
  Serial.println("Aguarde. Calibrando..."); 
  sensor.calibrate();
  Serial.println("Fim da calibração");
}
 
void loop() {
  // A frequência da corrente alternada no Brasil é 60 Hz. Mude caso necessário
  // A voltagem, no meu caso é 127
  delay(5000);
  float V = 220;
  float measure = sensor.getCurrentAC(60);
  float I = (measure - (measure*0.243)); // Multiplica pela constante de compensação
  float P = V * I;
 
  Serial.println(String("Corrente = ") + I + " A");
  Serial.println(String("Potência  = ") + P + " Watts");
 
}

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

/*
***Pinagem do Sensor RFID*** 	
----RFID------ESP82660------
*	3.3V	->	3.3V
*	RST 	->	D2
*	GND		->	GND
*	MISO	->	D6
*	MOSI	->	D7
*	SCK		->	D5
*	SDA		->	D4				
*/