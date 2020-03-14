#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN D4
#define RST_PIN D2
#define LedVerde 5
#define LedVermelho 0
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

MFRC522 mfrc522(SS_PIN, RST_PIN); //Instancia a Classe

void setup() {
  	// put your setup code here, to run once:
	Serial.begin(9600);
	SPI.begin(); //Inicia SPI bus
	mfrc522.PCD_Init(); //Inicia MFRC522
	Serial.println("RFID lendo UID");
	pinMode(LedVerde, OUTPUT);
	pinMode(LedVermelho, OUTPUT);
}

void loop() {
	
	// Procura por novas tags
	if ( ! mfrc522.PICC_IsNewCardPresent()){
		return;
	}
	// Seleciona uma das tags
	if ( ! mfrc522.PICC_ReadCardSerial()){
		return;
	}
	//Mostra UID na serial
	Serial.println("Tag UID:");
	String tagRecebida = "";
	for (byte i = 0; i < mfrc522.uid.size; i++){
		Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
		Serial.print(mfrc522.uid.uidByte[i], HEX);
		tagRecebida.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
		tagRecebida.concat(String(mfrc522.uid.uidByte[i], HEX));
	}
	Serial.println();
	tagRecebida.toUpperCase();
	if (tagRecebida.substring(1) == "3A 23 6E 19"){
		digitalWrite(LedVerde, HIGH);
		delay(1000);
		digitalWrite(LedVerde, LOW);
	}
	else
	{
		digitalWrite(LedVermelho, HIGH);
		delay(1000);
		digitalWrite(LedVermelho, LOW);
		delay(1000);
	}
	
		
	// 
	// digitalWrite(LedAmarelo, HIGH);
	// delay(1000);
	// digitalWrite(LedAmarelo, LOW);
	// delay(1000);
	// digitalWrite(LedVermelho, LOW);
	// delay(1000);
	// digitalWrite(LedVerde, LOW);
	// delay(1000);
}