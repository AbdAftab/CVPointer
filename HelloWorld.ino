#include <LiquidCrystal.h>
#include <SR04.h>
#include <pitches.h>
#include <Servo.h>

#define TRIG_PIN 4
#define ECHO_PIN 3 
Servo myservo;
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a,b;
String InBytes = "0";
String y = "0";
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  Serial.begin(9600);//Initialization of Serial Port
   delay(1000);
   myservo.attach(6);
   myservo.write(120);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Distance:");
}

void loop() {
  if (Serial.available() > 0){
  InBytes = Serial.readStringUntil('\n');}
  b = 180-(InBytes.toInt()/2.4);
  myservo.write(b);
  lcd.setCursor(0,0);
  lcd.print("Distance:");
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(b);
  lcd.setCursor(13,1);
//  while (a < 183){
//    a=sr04.Distance();
//    lcd.print("TOO CLOSE");
//    lcd.setCursor(13,1);
//    lcd.print("--");
//    tone(2,NOTE_D5,250);
//    }

}
