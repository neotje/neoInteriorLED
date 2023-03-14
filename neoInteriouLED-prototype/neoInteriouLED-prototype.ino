const int POT_PIN = A1;
const int ON_POS_PIN = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(POT_PIN, INPUT);
  pinMode(ON_POS_PIN, INPUT);

  ledControlSetup();
}

int value = 0;
bool isOnPos = false;

void loop() {
  // put your main code here, to run repeatedly:
  isOnPos = !digitalRead(ON_POS_PIN);

  value = analogRead(POT_PIN);
  value = map(value, 0, 1023, 0, 255);
  
  ledControlSetOff(!isOnPos);
  setBrightness(value);

  ledControlLoop();
}
