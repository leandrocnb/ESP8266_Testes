 
/*
 * Created by K. Suwatchai (Mobizt)
 * 
 * Email: k_suwatchai@hotmail.com
 * 
 * Github: https://github.com/mobizt
 * 
 * Copyright (c) 2019 mobizt
 * 
 * This example is for the beginner
 *
*/
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

//1. Change the following info
#define FIREBASE_HOST "testesp8266-50ca3.firebaseio.com"
#define FIREBASE_AUTH "FZtCcCodtYjSyRYA1qtQAyrqXAzcJhZHR76nkpR1"
#define WIFI_SSID "MaxtorIV"
#define WIFI_PASSWORD "HYjvpJYv"


//2. Define FirebaseESP8266 data object for data sending and receiving
FirebaseData firebaseData;

//Led
#define  ledGreen 5

void setup()
{

  Serial.begin(9600);

  //Define  ledGreen Output
  pinMode(ledGreen, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();


  //3. Set your Firebase info
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  //4. Enable auto reconnect the WiFi when connection lost
  Firebase.reconnectWiFi(true);

  //5. Try to set int data to Firebase
  //The set function returns bool for the status of operation
  //firebaseData requires for sending the data
  if(Firebase.setInt(firebaseData, "/LED_Status", 0))
  {
    //Success
     Serial.println("Set int data success");

  }else{
    //Failed?, get the error reason from firebaseData
    Serial.print("Error in setInt, ");
    Serial.println(firebaseData.errorReason());
  }

}

void loop()
{
   if(Firebase.getInt(firebaseData, "/LED_Status"))
  {
    //Success
    Serial.print("Get int data success, int = ");
    if(firebaseData.intData() == 1){
      digitalWrite(ledGreen, HIGH);
      Serial.println("Led ON");
    }
    else if (firebaseData.intData() == 0){
      digitalWrite(ledGreen, LOW);
      Serial.println("Led OFF");
    }

  }else{
    //Failed?, get the error reason from firebaseData
    Serial.print("Error in getInt, ");
    Serial.println(firebaseData.errorReason());
  }
  delay(1000);
}