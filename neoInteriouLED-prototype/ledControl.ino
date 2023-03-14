const int PWM_PIN = 0;
const int INTERVAL = 20;

int brightness = 0;
int targetBrightness = 255 / 2;

bool isOff = true;

unsigned long previousMillis = 0;

void setBrightness(int newBrightness) {
  if (newBrightness > 255)
    targetBrightness = 255;
  else if (newBrightness < 0)
    targetBrightness = 0;
  else
    targetBrightness = newBrightness;
}

void ledControlSetOff(bool off) {
  isOff = off;
}

void ledControlSetup() {
  pinMode(PWM_PIN, OUTPUT);
}

void ledControlLoop() {
  if (millis() > previousMillis + INTERVAL) {
    previousMillis = millis();

    if (isOff) {
      if(brightness > 0)
        brightness--;
    } else if (brightness > targetBrightness) {
      brightness--;
    } else if (brightness < targetBrightness) {
      brightness++;
    }

    analogWrite(PWM_PIN, brightness);
  }
}
