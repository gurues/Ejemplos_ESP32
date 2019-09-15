#include <Arduino.h>
#include "WiFi.h"

//Definido LED_BUILTIN en pin 2 en platformio.ini o en el framework de Arduino
// Blink
void blink(unsigned int t){
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(t);                       // wait for a second
}

// Buscador de redes WIFI
void Scaner_WIFI(){
    Serial.println("scan start");

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" OPEN":" ENCRYP");
            delay(10);
        }
    }
    Serial.println("");
    delay(5000);
}

// Funcion para probar el detector hall interno del esp32.
void Prueba_Hall() {

    int val = 0;
    // read hall effect sensor value
    val = hallRead();
    // print the results to the serial monitor
    Serial.print("Lectura Sensor Hall = ");
    Serial.println(val); 

    delay(2000);

}


// Funcion para probar entradas touch
void Pusador_Capacitivo(int pintouch, int tarado){

    // set pin numbers
    const int touchPin = pintouch; 

    // change with your threshold value
    const int threshold = tarado;
    // variable for storing the touch pin value 
    int touchValue;
    // read the state of the pushbutton value:
    touchValue = touchRead(touchPin);
    Serial.print("Lectura Pin Capacitivo = ");
    Serial.print(touchValue);
    // check if the touchValue is below the threshold
    // if it is, set LED_BUILTIN to HIGH
    if(touchValue < threshold){
        // turn LED on
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.println(" - LED on");
    }
    else{
        // turn LED off
        digitalWrite(LED_BUILTIN, LOW);
        Serial.println(" - LED off");
    }
    delay(2000);

}

// Funcion temperatura interna ES32

#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();

void Temp_ESP(){
    // Convierte al temperatura a Centigrados.
    Serial.print("Temperatura Interna ESP32 = ");
    Serial.print((temprature_sens_read() - 32) / 1.8);
    Serial.println(" C");
    delay(5000);
}