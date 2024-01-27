//
// Información sobre la placa HuskyLens y el código en:
// https://wiki.dfrobot.com/HUSKYLENS_V1.0_SKU_SEN0305_SEN0336
//

#include "HUSKYLENS.h"
#include "SoftwareSerial.h"

// Define huskylens como una instancia de la clase HUSKYLENS para interactuar con la placa.
HUSKYLENS huskylens;

// Configura una conexión serial de software en los pines 10 y 11.
SoftwareSerial mySerial(10, 11); // Pin 10 conectado a RX de HUSKYLENS, Pin 11 a TX.

void setup() {
    // Inicia la comunicación serial con la computadora.
    Serial.begin(9600);
    // Inicia la comunicación serial con HuskyLens.
    mySerial.begin(9600);

    // Intenta iniciar la comunicación con HuskyLens hasta que tenga éxito.
    while (!huskylens.begin(mySerial)) {
        Serial.println(F("¡Ha fallado!"));
        Serial.println(F("1. Asegúrate de que la HUSKYLENS esté configurada en: (General Settings>>Protocol Type>>Serial 9600)"));
        Serial.println(F("2. Comprueba las conexiones de nuevo."));
        delay(100);
    }
}

void loop() {
    // Solicita datos a HuskyLens.
    if (!huskylens.request()) {
        Serial.println(F("Fallo al pedir datos a la HUSKYLENS, comprueba las conexiones."));
    } else {
        verificarTipoDeCamara();
    }
}

void verificarTipoDeCamara()
{
    // Verifica si el modelo es Pro o Estándar
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("");
    Serial.println("-------------------------------------");
    delay(10);
    bool esPro;
    esPro = huskylens.isPro();
    if (esPro)
    {
        Serial.println("    Modelo profesional detectado");
    }
    else
    {
        Serial.println("    Modelo estándar detectado");
    }
    Serial.println("-------------------------------------");

    Serial.println("Verificación de cámara completada");
    int contadorTemporizador = 0;
    
    // Creación de una espera
    while (contadorTemporizador < 4)
    {
        Serial.print(".");
        delay(1000);
        contadorTemporizador++;
    }
    delay(1000);
    Serial.println(".");
}