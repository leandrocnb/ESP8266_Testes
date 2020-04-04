// #include <Arduino.h>
// #include <SPI.h>
// #include <MFRC522.h>

// #define SS_PIN 2 //D4
// #define RST_PIN 4 //D2
// #define LedGreen 5 //D1
// #define LedRed 0 //D3
// #define HIGTH 

// MFRC522 mfrc522(SS_PIN, RST_PIN); //Instancia a Classe

// void setup() {
//   	// put your setup code here, to run once:
// 	Serial.begin(9600);
// 	SPI.begin(); //Inicia SPI bus
// 	mfrc522.PCD_Init(); //Inicia MFRC522
// 	Serial.println("Aproxime o seu cartao do leitor...");
// 	pinMode(LedGreen, OUTPUT);
// 	pinMode(LedRed, OUTPUT);
// 	digitalWrite(LedGreen, HIGH);
// }

// void loop() {
	
// 	// Procura por novas tags
// 	if ( ! mfrc522.PICC_IsNewCardPresent()){
// 		return;
// 	}
// 	// Seleciona uma das tags
// 	if ( ! mfrc522.PICC_ReadCardSerial()){
// 		return;
// 	}
// 	//Mostra UID na serial
// 	Serial.println("Tag UID:");
// 	String tagRecebida = "";
// 	for (byte i = 0; i < mfrc522.uid.size; i++){
// 		Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
// 		Serial.print(mfrc522.uid.uidByte[i], HEX);
// 		tagRecebida.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
// 		tagRecebida.concat(String(mfrc522.uid.uidByte[i], HEX));
// 	}
// 	Serial.println();
// 	tagRecebida.toUpperCase();
// 	if (tagRecebida.substring(1) == "3A 23 6E 19")
// 		digitalWrite(LedGreen, LOW);
// 	else
// 		digitalWrite(LedGreen, HIGH);
		
// }

// /*		Placa NODEMCU
// * 	0	-> 	D3
// * 	1	-> 	TX
// * 	2	-> 	D4
// * 	3	-> 	RX
// * 	4	-> 	D2
// * 	5	-> 	D1
// * 	12	-> 	D6
// * 	13	-> 	D7
// * 	14	-> 	D5
// * 	14	-> 	D8
// * 	16	-> 	D0
// */

// /*
// ***Pinagem do Sensor RFID*** 	
// ----RFID------ESP82660------
// *	3.3V	->	3.3V
// *	RST 	->	D2
// *	GND		->	GND
// *	MISO	->	D6
// *	MOSI	->	D7
// *	SCK		->	D5
// *	SDA		->	D4				
// */