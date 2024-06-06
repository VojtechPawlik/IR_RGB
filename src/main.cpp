#include <Arduino.h>
#include <IRremote.hpp>

const int RECEIVER_PIN = 12;
const unsigned long CONFIRM_CODE = 4127850240; // Kód klávesy ENTER
const int LED_RED = 6;
const int LED_GREEN = 5;
const int LED_BLUE = 9;

const unsigned long buttonCodes[] = {
    3910598400, // 0
    4077715200, // 1
    3877175040, // 2
    2707357440, // 3
    4144561920, // 4
    3810328320, // 5
    2774204160, // 6
    3175284480, // 7
    2907897600, // 8
    3041591040, // 9
};

String enteredNumber = "";
int currentLED = 0; // 0 = red, 1 = green, 2 = blue

const int totalCodes = sizeof(buttonCodes) / sizeof(buttonCodes[0]);

String decodeNumber(unsigned long code) {
  for (int i = 0; i < totalCodes; i++) {
    if (code == buttonCodes[i]) {
      return String(i);
    }
  }
  return ""; // V případě, že kód neodpovídá žádnému známému číslu
}

void setLED(int intensity) {
  switch (currentLED) {
    case 0:
      analogWrite(LED_RED, intensity);
      Serial.print("Red LED intensity: ");
      Serial.println(intensity);
      currentLED = 1; // Přechod na další LED
      break;
    case 1:
      analogWrite(LED_GREEN, intensity);
      Serial.print("Green LED intensity: ");
      Serial.println(intensity);
      currentLED = 2; // Přechod na další LED
      break;
    case 2:
      analogWrite(LED_BLUE, intensity);
      Serial.print("Blue LED intensity: ");
      Serial.println(intensity);
      currentLED = 0; // Zpět na první LED
      break;
    default:
      Serial.println("Invalid LED state");
      break;
  }
}

void setup() {
  IrReceiver.begin(RECEIVER_PIN, ENABLE_LED_FEEDBACK); // Inicializace přijímače
  Serial.begin(9600); // Seriová komunikace

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);

  Serial.println("Setup completed");
}

void loop() {
  if (IrReceiver.decode()) { // Pokud přijímač přijme data
    unsigned long receivedCode = IrReceiver.decodedIRData.decodedRawData; // Uložení přijatého kódu
    if (receivedCode != 0xFFFFFFFF) { // Ověření platnosti kódu
      Serial.print("Received code: ");
      Serial.println(receivedCode);
      if (receivedCode == CONFIRM_CODE) { // Pokud je přijato ENTER
        int number = enteredNumber.toInt(); // Převedení řetězce na číslo
        if (number >= 0 && number <= 255) { // Ověření rozsahu čísla
          setLED(number);
          Serial.print("Set intensity to: ");
          Serial.println(number);
        } else {
          Serial.println("Value out of range");
        }
        enteredNumber = ""; // Vymazání akumulovaného čísla
      } else {
        enteredNumber += decodeNumber(receivedCode); // Přidání čísla k akumulovanému
        Serial.print("Accumulated number: ");
        Serial.println(enteredNumber);
      }
    }
    IrReceiver.resume(); // Připravit přijímač na další data
  }
}
