
#define LM1 6 // Whatever these are 
#define LM2 5
#define RM1 10
#define RM2 9

#define N  'F'
#define NE 'E'
#define E  'R'
//#define SE 'C'
#define S  'G'
#define SW 'Z'
#define W  'L'
#define NW 'Q'
//#define S  'S'

char incomingByte;
unsigned long currentTime, lastCommandTime, autoOFF;

void setup() {
  Serial.begin(9600); // Init serial
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(LM1, OUTPUT); // Output to left motor pin 1
  pinMode(LM2, OUTPUT); // and pin 2
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  autoOFF = 500;        // How long the car moves before stopping if no connection
  currentTime = millis();
  lastCommandTime = currentTime;

}

void loop() {
  // These 4 lines are for testing purposes
  controlCar(1, 0, 1, 0); // 
  delay(1000);            // wait for a second
  controlCar(0, 1, 0, 1);
  delay(1000);
  
  if (Serial.available() > 0) { // If there is data from bluetooth
    incomingByte = Serial.read();
    controlCar(1, 0, 1, 0);
    delay(10000);
    }
  
/*
  while (Serial.available() > 1) { // clear all but the latest byte
    incomingByte = Serial.read(); // read byte
  }

  if (Serial.available() > 0) { // Read only the latest command
    incomingByte = Serial.read();
  }
  // If no new command, use the last command

  if (millis() - lastCommandTime > autoOFF) { // If too long since last command, stop car
    controlCar(1, 1, 1, 1);
  }
  else if (incomingByte == N) { // Depending on command, set the motor directions
    controlCar(1, 0, 1, 0);
  }
  else if (incomingByte == NE) {
    controlCar(1, 0, 0, 0);
  }
  else if (incomingByte == E) {
    controlCar(1, 0, 0, 1);
  }
  else if (incomingByte == SE) {
    controlCar(0, 0, 0, 1);
  }
  else if (incomingByte == S) {
    controlCar(0, 1, 0, 1);
  }
  else if (incomingByte == SW) {
    controlCar(0, 1, 0, 0);
  }
  else if (incomingByte == W) {
    controlCar(0, 1, 1, 0);
  }
  else if (incomingByte == NW) {
    controlCar(0, 0, 1, 0);
  }
  else if (incomingByte == S) {
    controlCar(1, 1, 1, 1);
  }
*/
}

// Car/motor control function, arguments are booleans (0 or 1)
// 1,0 or 0,1 the motor spins one way or another, 1,1 or 0,0 stops it
void controlCar(int left1, int left2, int right1, int right2) {
  digitalWrite(LM1, left1);
  digitalWrite(LM2, left2);
  digitalWrite(RM1, right1);
  digitalWrite(RM2, right2);
}


