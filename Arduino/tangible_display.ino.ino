#include <Arduino.h>

#define NUM_MOTORS 9

// -------------------- MOTOR STRUCT --------------------
struct Motor {
  int in1, in2, in3, in4, en;
};

// -------------------- PIN MAP (9 MOTORS) --------------------
Motor motors[NUM_MOTORS] = {

  {2, 3, 4, 5, 22},
  {6, 7, 8, 9, 23},
  {10, 11, 12, 13, 24},

  {25, 26, 27, 28, 29},
  {30, 31, 32, 33, 34},
  {35, 36, 37, 38, 39},

  {40, 41, 42, 43, 44},
  {45, 46, 47, 48, 49},
  {50, 51, 52, 53, 21}
};

// -------------------- STATE --------------------
long pos[NUM_MOTORS];
unsigned long lastCommandTime = 0;
const int timeout = 3000;

// -------------------- STEP SEQUENCE --------------------
void stepMotor(Motor m, int s) {
  switch (s % 4) {

    case 0:
      digitalWrite(m.in1, HIGH);
      digitalWrite(m.in2, LOW);
      digitalWrite(m.in3, HIGH);
      digitalWrite(m.in4, LOW);
      break;

    case 1:
      digitalWrite(m.in1, LOW);
      digitalWrite(m.in2, HIGH);
      digitalWrite(m.in3, HIGH);
      digitalWrite(m.in4, LOW);
      break;

    case 2:
      digitalWrite(m.in1, LOW);
      digitalWrite(m.in2, HIGH);
      digitalWrite(m.in3, LOW);
      digitalWrite(m.in4, HIGH);
      break;

    case 3:
      digitalWrite(m.in1, HIGH);
      digitalWrite(m.in2, LOW);
      digitalWrite(m.in3, LOW);
      digitalWrite(m.in4, HIGH);
      break;
  }
}

// -------------------- MOTOR ENABLE --------------------
void setEnable(int i, bool state) {
  digitalWrite(motors[i].en, state ? HIGH : LOW);
}

// -------------------- MOVE MOTOR --------------------
void moveMotor(int i, int steps) {

  setEnable(i, true);

  int dir = (steps > 0) ? 1 : -1;

  for (int j = 0; j < abs(steps); j++) {
    pos[i] += dir;
    stepMotor(motors[i], pos[i]);
    delay(2);
  }
}

// -------------------- STOP ALL MOTORS --------------------
void disableAll() {
  for (int i = 0; i < NUM_MOTORS; i++) {

    setEnable(i, false);

    digitalWrite(motors[i].in1, LOW);
    digitalWrite(motors[i].in2, LOW);
    digitalWrite(motors[i].in3, LOW);
    digitalWrite(motors[i].in4, LOW);
  }
}

// -------------------- BLUETOOTH INIT --------------------
void initBluetooth() {
  Serial.begin(115200);   // USB debug
  Serial1.begin(9600);    // HC-05
}

// -------------------- PIN INIT --------------------
void initPins() {

  for (int i = 0; i < NUM_MOTORS; i++) {

    pinMode(motors[i].in1, OUTPUT);
    pinMode(motors[i].in2, OUTPUT);
    pinMode(motors[i].in3, OUTPUT);
    pinMode(motors[i].in4, OUTPUT);
    pinMode(motors[i].en, OUTPUT);

    setEnable(i, false);

    digitalWrite(motors[i].in1, LOW);
    digitalWrite(motors[i].in2, LOW);
    digitalWrite(motors[i].in3, LOW);
    digitalWrite(motors[i].in4, LOW);

    pos[i] = 0;
  }
}

// -------------------- COMMAND PARSER --------------------
void parseCommand(String cmd) {

  if (cmd.startsWith("S")) {

    int index = cmd.substring(1, cmd.indexOf(':')).toInt();
    int value = cmd.substring(cmd.indexOf(':') + 1).toInt();

    if (index >= 0 && index < NUM_MOTORS) {
      moveMotor(index, value);
    }
  }
}

// -------------------- SETUP --------------------
void setup() {
  initBluetooth();
  initPins();

  Serial.println("3x3 Tangible Display Ready");
}

// -------------------- LOOP --------------------
void loop() {

  String cmd = "";

  // Bluetooth input
  if (Serial1.available()) {
    cmd = Serial1.readStringUntil('\n');
    Serial.println(cmd);

    lastCommandTime = millis();
    parseCommand(cmd);
  }

  // safety shutdown (heat control)
  if (millis() - lastCommandTime > timeout) {
    disableAll();
  }
}