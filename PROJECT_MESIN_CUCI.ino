/* Sketch for Tutorial 14
Author: Maximilian Hentsch
Sketch zu Arduino Tutorial 14 - Displaymenü
https://www.youtube.com/watch?v=DuAG98P9Seo
*/


#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

int upButton = 7;
int downButton = 6;
int selectButton = 5;
int menu = 1;

void setup() {
  lcd.begin(20,4);
 
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  updateMenu();
  submenu();
}

void loop() {
  if (!digitalRead(downButton)){
    menu++;
    updateMenu();
    delay(100);
    while (!digitalRead(downButton));
  }
  if (!digitalRead(upButton)){
    menu--;
    updateMenu();
    delay(100);
    while(!digitalRead(upButton));
  }
  if (!digitalRead(selectButton)){
    submenu();
    updateMenu();
    //eksekusi();
    delay(100);
    while (!digitalRead(selectButton));
  }
}

void updateMenu() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print("Air Yang Digunakan");
      lcd.setCursor(0,1);
      lcd.print(">Sedikit");
      lcd.setCursor(0, 2);
      lcd.print(" Sedang");
      lcd.setCursor(0,3);
      lcd.print(" Banyak");
      break;
    case 2:
      lcd.clear();
      lcd.print("Air Yang Digunakan");
      lcd.setCursor(0,1);
      lcd.print(" Sedikit");
      lcd.setCursor(0,2);
      lcd.print(">Sedang");
      lcd.setCursor(0,3);
      lcd.print(" Banyak");
      break;
    case 3:
      lcd.clear();
      lcd.print("Air Yang Digunakan");
      lcd.setCursor(0,1);
      lcd.print(" Sedikit");
      lcd.setCursor(0,2);
      lcd.print(" Sedang");
      lcd.setCursor(0,3);
      lcd.print(">Banyak");
      break;
    case 4:
      menu = 3;
      break;
  }
}

void submenu() {
  switch (menu) {
    case 5:
    menu = 1;
    break;
    case 6:
    lcd.clear();
    lcd.print("Anda Yakin?");
    lcd.setCursor(0,1);
    lcd.print(">Ya");
    lcd.setCursor(0,2);
    lcd.print(" Tidak");
      //action1();
      break;
    case 7:
    lcd.clear();
    lcd.print("Anda Yakin?");
    lcd.setCursor(0,1);
    lcd.print(" Ya");
    lcd.setCursor(0,2);
    lcd.print(">Tidak");
     // action2();
      break;
  }
}

void action1() {
  lcd.clear();
  lcd.print("Yakin?");
  lcd.setCursor(0,1);
  lcd.print(">Ya");
  lcd.setCursor(0,2);
  lcd.print(" Tidak");
  delay(1500);
}
void action2() {
  lcd.clear();
  lcd.print(">Executing #2");
  delay(1500);
}
void action3() {
  lcd.clear();
  lcd.print(">Executing #3");
  delay(1500);
}
