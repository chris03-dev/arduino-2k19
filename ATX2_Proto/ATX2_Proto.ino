#include <ATX2.h>
#include <ATX2_gp2d120_lib.h>
int x = 0, CL = 500, CR = 450;
int IR = A0;

void setup() { 
  Serial.begin(9600);
  OK(); // Wait for OK button
  glcdClear(); // Clear screen 
} 
void loop() {
  fda(40);
  if (analog(0) > CL)
  {
    bk(50);
    delay(300);
    sra(50);
    delay(800);
  }
  if (analog(1) > CR)
  {
    bk(50);
    delay(500);
    sla(50);
    delay(900);
  }
  if (analog(2) > 50)
  {
      fda(100);
      delay(200);
  }
}

void fda(int x) {
  motor(1, x);
  motor(2, x);
  motor(3, x);
  motor(4, x);
}

void bk2a (int x, int y) {
  motor(1, -x);
  motor(2, -y);
  motor(3, -x/2);
  motor(4, -y/2);
}
void sra(int power) {
  motor(1, power);
  motor(2, -power);
  motor(3, power);
  motor(4, -power);
}
void sla(int power) {
  motor(1, -power);
  motor(2, power);
  motor(3, -power);
  motor(4, power);
}
