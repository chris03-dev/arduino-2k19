#include "LedControl.h"
#include "binary.h"

/*
 DIN connects to pin 12
 CLK connects to pin 11
 CS connects to pin 10 
*/
LedControl lc = LedControl(12,11,10,1);
int limit = 5,
fruitx = random(8),
fruity = random(8),
snake_x[64],
snake_y[64],
dir = 4;

boolean ovl = false;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0); 
  Serial.begin(9600);
  snake_x[0] = 5;snake_y[0] = 4;
  snake_x[1] = 4;snake_y[1] = 4;
  snake_x[2] = 3;snake_y[2] = 4;
  snake_x[3] = 2;snake_y[3] = 4;
  snake_x[4] = 1;snake_y[4] = 4;
}

void drawUpdate(){
  //Fruit
  int fruitxf = int(pow(2, fruitx));
  if (fruitxf > 2) fruitxf++;
  
  Serial.println(String(fruitx) + "," + String(fruity));
  
  lc.setRow(0, fruity, fruitxf);
  
  
  //Snake
  int 
    snake_xi = snake_x[0],
    snake_yi = snake_y[0],
    snake_xf[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  Serial.println("BEFORE:");
  for (int i = 0; i < limit; i++) {
    Serial.println(String(snake_x[i])+ "," + String(snake_y[i]));
  }
  for (int i = 63; i > 0; i--) {
    snake_x[i] = snake_x[i - 1];
    snake_y[i] = snake_y[i - 1];
  }
  
  Serial.println("AFTER:");
  for (int i = 0; i < limit; i++) {
    Serial.println(String(snake_x[i])+ "," + String(snake_y[i]));
  }
  
  if (dir == 2) {
    if (snake_y[1] > 0) {
      snake_y[0] = snake_y[1] - 1;
    }
    else restart();
  }
  if (dir == 3) {
    if (snake_y[1] < 7) {
      snake_y[0] = snake_y[1] + 1;
    }
    else restart();
  }
  if (dir == 4) {
    if (snake_x[1] < 7) {
      snake_x[0] = snake_x[1] + 1;
    }
    else restart();
  }
  if (dir == 5) {
    if (snake_x[1] > 0) {
      snake_x[0] = snake_x[1] - 1;
    }
    else restart();
  }

  if ((snake_x[0] == fruitx)
  &&(snake_y[0] == fruity)) {
    ateSomething();
  }

  for (int i = 1; i < limit; i++)
  if (snake_x[0] == snake_x[i]) {
    if (snake_y[0] == snake_y[i]) restart();
  }
  
  lc.setIntensity(0,8);
  for (int i = 0; i < limit; i++) {
    snake_xf[snake_y[i]] += int(pow(2, snake_x[i]));
    if (int(pow(2, snake_x[i])) >= 3) snake_xf[snake_y[i]]++;
    
    Serial.println(String(snake_xf[snake_y[i]]) + "+=" + String(pow(2, snake_x[i])));
    
    if (fruity == snake_y[i]) {
      lc.setRow(0,snake_y[i],snake_xf[snake_y[i]] + fruitxf);
    }
    else lc.setRow(0,snake_y[i],snake_xf[snake_y[i]]);
  }
  Serial.println("\n" + String(dir) + " <= DIR");
  delay(250);
}

//x = 4;
//xr = pow(2, x);

void IOUpdate() {
  for (int i = 0; i < 250; i++) {
    if ((digitalRead(2) == HIGH)&&(dir != 3)) dir = 2;
    if ((digitalRead(3) == HIGH)&&(dir != 2)) dir = 3;
    if ((digitalRead(4) == HIGH)&&(dir != 5)) dir = 4;
    if ((digitalRead(5) == HIGH)&&(dir != 4)) dir = 5;
    delay(1);
  }
}

void restart() {
  Serial.println("AFFIRMATIVE");
  limit = 5;
  fruitx = random(8);
  fruity = random(8);
  
  dir = 4;
  lc.clearDisplay(0); 
  snake_x[0] = 5;snake_y[0] = 4;
  snake_x[1] = 4;snake_y[1] = 4;
  snake_x[2] = 3;snake_y[2] = 4;
  snake_x[3] = 2;snake_y[3] = 4;
  snake_x[4] = 1;snake_y[4] = 4;
}

void ateSomething() {
  limit++;

  do {
    fruitx = random(8);
    fruity = random(8);
    ovl = false;
    
    for (int i = 0; i < 64; i++) {
      if ((snake_x[i] == fruitx)
      &&(snake_y[i] == fruity))
          ovl = true;
    }
  }
  while (ovl == false);  
  
  int fruitxf = int(pow(2, fruitx));
  if (fruitxf > 2) fruitxf++;
  
  lc.setRow(0, fruity, fruitxf);
}
void loop(){
  drawUpdate();
  IOUpdate();
  lc.clearDisplay(0);
}
