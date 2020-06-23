// #include <Arduino.h>
// #if defined(ESP8266)
// #include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
// #else
// #include <WiFi.h>          //https://github.com/esp8266/Arduino
// #endif

// //needed for library
// #include <DNSServer.h>
// #if defined(ESP8266)
// #include <ESP8266WebServer.h>
// #else
// #include <WebServer.h>
// #endif
// #include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager

// #include <FirebaseArduino.h>
// #include <ESP8266HTTPClient.h>

// //for LED status
// #include <Ticker.h>
// Ticker ticker;
// #define ledRed 0

// //for Settings  Up Firebase
// #define FIREBASE_HOST "testesp8266-50ca3.firebaseio.com"             // the project name address from firebase id
// #define FIREBASE_AUTH "FZtCcCodtYjSyRYA1qtQAyrqXAzcJhZHR76nkpR1"       // the secret key generated from firebase
// #define ledGreen 5
// String fireStatus = "";                                                     // led status received from firebase

// void tick() {
// 	//toggle state
// 	int state = digitalRead(ledRed);  // get the current state of GPIO1 pin
// 	digitalWrite(ledRed, !state);     // set pin to the opposite state
// }

// //gets called when WiFiManager enters configuration mode
// void configModeCallback (WiFiManager *myWiFiManager) {
// 	Serial.println("Entered config mode");
// 	Serial.println(WiFi.softAPIP());
// 	//if you used auto generated SSID, print it
// 	Serial.println(myWiFiManager->getConfigPortalSSID());
// 	//entered config mode, make led toggle faster
// 	ticker.attach(0.2, tick);
// }

// void setup() {
// 	// put your setup code here, to run once:
// 	Serial.begin(9600);
	
// 	//set led pin as output
// 	pinMode(ledRed, OUTPUT);
// 	pinMode(ledGreen, OUTPUT);
// 	// start ticker with 0.5 because we start in AP mode and try to connect
// 	ticker.attach(0.6, tick);

// 	//WiFiManager
// 	//Local intialization. Once its business is done, there is no need to keep it around
// 	WiFiManager wifiManager;
// 	//reset settings - for testing
// 	//wifiManager.resetSettings();

// 	//set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
// 	wifiManager.setAPCallback(configModeCallback);

// 	//fetches ssid and pass and tries to connect
// 	//if it does not connect it starts an access point with the specified name
// 	//here  "AutoConnectAP"
// 	//and goes into a blocking loop awaiting configuration
// 	if (!wifiManager.autoConnect("ESP-AgenLavan", "agAdminESP")) {
// 		Serial.println("failed to connect and hit timeout");
// 		//reset and try again, or maybe put it to deep sleep
// 		ESP.restart();
// 		delay(1000);
// 	}

// 	//if you get here you have connected to the WiFi
// 	Serial.println("connected...yeey :)");
// 	ticker.detach();
// 	//keep LED on
// 	digitalWrite(ledRed, HIGH);

// }

// void loop() {
		
// 	// put your main code here, to run repeatedly:
	
// }

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