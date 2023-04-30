#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

float xn1 = 0;
float yn1 = 0;
int k = 0;

void setup() {
  Serial.begin(115200);

  if (!lox.begin()) {
    while (1);
  }

  lox.startRangeContinuous();
}


void loop() {

  if (lox.isRangeComplete()) {
    float  xn = lox.readRange();

    float yn = 0.93908194 * yn1 + 0.03045903 * xn + 0.03045903 * xn1;

    xn1 = xn;
    yn1 = yn;

    if (k % 3 == 0) {
      // Output
      Serial.print(2 * xn);
      Serial.print(" ");
      Serial.println(2 * yn);
    }
    k = k + 1;

  }


}
