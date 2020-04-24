
#include <Servo.h>

Servo s1;  // create servo object to control a servo
Servo s2;
int p1 = 90;
int p2 = 25;
int randNumber;

void setup() {
  // put your setup code here, to run once:
s1.attach(9);
s2.attach(10);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}
//s2 0 = horizontal
//s1 0 = horizontal at self
//90/90 = straight down
//s1 25 to 155
//s2 115 to 90
void loop() {
  digitalWrite(12, HIGH);
  for (int i = 0; i < 5; i++) {
    digitalWrite(12, HIGH);
    randNumber = random(5);
    switch (randNumber) {
      case 0:
        zigzag(15);
      break;
      case 1:
        square(15);
      break;
      case 2:
        square(5);
      break;
      case 3:
        squareSquiggles(15);
      break;
      case 4:
        squareSquiggles(50);
      break;
      }
      digitalWrite(12, LOW);
      delay(random(10000));
  }
  delay(random(5000, 300000));
}
void square(int w) {
  move(65, 65, w);
  move(65, 115, w);
  move(115, 115, w);
  move(115, 65, w);
}
void zigzag(int w) {
  move(115, 115, w);
  move(90, 110, w);
  move(115, 100, w); 
  move(90, 90, w);
  move(115, 80, w);
  move(90, 70, w);
}
void squareSquiggles(int w) {
  move(65, 65, w);
  for (int i = 0; i < 5; i++) {
    move(55, 65, w/5);
    move(75, 65, w/5);
  }
  move(65, 115, w);
  for (int i = 0; i < 5; i++) {
    move(55, 115, w/5);
    move(75, 115, w/5);
  }
    move(115, 115, w);
  for (int i = 0; i < 5; i++) {
    move(105, 115, w/5);
    move(125, 115, w/5);
  }
  move(115, 65, w);
  for (int i = 0; i < 5; i++) {
    move(105, 65, w/5);
    move(125, 65, w/5);
  }
}
void move(int d1, int d2, int w) {
  while (s1.read() != d1 || s2.read() != d2) {
      int x1 = s1.read();
      int x2 = s2.read();
      if (x1 < d1) x1++;
      else if (x1 > d1) x1--;
      if (x2 < d2) x2++;
      else if (x2 > d2) x2--;
      s1.write(x1);
      s2.write(x2);
      delay(w);
  }
}
