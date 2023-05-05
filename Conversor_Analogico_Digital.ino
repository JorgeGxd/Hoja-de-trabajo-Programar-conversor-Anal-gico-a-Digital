const int LDR_PIN = A0; // Pin de la fotorresistencia
const int LED_PIN = 5; // Pin del LED
const int THRESHOLD = 500; // Umbral de intensidad de luz

class LDR {
  public:
    LDR(int pin) {
      _pin = pin;
      pinMode(_pin, INPUT);
    }

    int getIntensity() {
      return analogRead(_pin);
    }

    void checkIntensity() {
      int intensity = getIntensity();

      Serial.print("Intensidad de luz: ");
      Serial.println(intensity);

      if (intensity > THRESHOLD && !_ledOn) {
        digitalWrite(LED_PIN, HIGH);
        _ledOn = true;
        Serial.println("LED encendido");
      } else if (intensity <= THRESHOLD && _ledOn) {
        digitalWrite(LED_PIN, LOW);
        _ledOn = false;
        Serial.println("LED apagado");
      }
    }

  private:
    int _pin;
    bool _ledOn = false;
};

LDR ldr(LDR_PIN);

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  ldr.checkIntensity();
  delay(1000);
}
