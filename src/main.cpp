#include <Arduino.h>

// Descomentar para ejecutar el ejemplo de código ESP32
//#define Prueba_Blink
//#define Prueba_WIFI_scan
//#define Prueba_Sensor_Hall
//#define Prueba_Pulsador_Capacitivo
//#define Prueba_Sensor_Temperatura
//#define Prueba_BLE_scan
//#define Prueba_BLE_servidor

// Se ejecuta cuando se prueba el código BLE scan
#ifdef Prueba_BLE_scan
    #include <BLE_scan.h>
    #define BLE
#endif

// Se ejecuta cuando se prueba el código BLE servidor
#ifdef Prueba_BLE_servidor
    #include <BLE_servidor.h>
    #define BLE
#endif

// Se ejecuta cuando se prueban códigos que no activan Bluetooth
#ifndef BLE
    #include <funciones.h>
#endif


void setup()
{
    
    pinMode (LED_BUILTIN, OUTPUT);
    Serial.begin(115200);

    #ifdef Prueba_WIFI_scan
        // Set WiFi to station mode and disconnect from an AP if it was previously connected
        WiFi.mode(WIFI_STA);
        WiFi.disconnect();
        delay(100);
        Serial.println("Setup WIFI done");
    #endif

    #ifdef Prueba_BLE_scan
        // Scan Bluetooth
        BLE_Scanning();
    #endif

    #ifdef Prueba_BLE_servidor
        // Scan Bluetooth
        BLE_server();
    #endif

}

void loop(){

    #ifdef Prueba_Blink
        // Hola mundo
        blink(1000U);
    #endif

    #ifdef Prueba_WIFI_scan
        // Scaner WIFI
        Scaner_WIFI();
    #endif

    #ifdef Prueba_Pulsador_Capacitivo
        // Prueba pulsador capacitivo pin GPIO 4 y un nivel de activacion de inferior a 20
        Pusador_Capacitivo(4, 20);
    #endif

    #ifdef Prueba_Sensor_Hall
        // Prueba sensor hall interno ESP32
        Prueba_Hall();
    #endif

    #ifdef Prueba_Sensor_Temperatura
        // Prueba sensor Temperatura interno ESP32
        Temp_ESP();
    #endif

    #ifdef BLE
        delay(3000);
    #endif

}