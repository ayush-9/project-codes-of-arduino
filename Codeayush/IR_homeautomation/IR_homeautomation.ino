#include <LiquidCrystal.h>
#include<string.h>
#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
#define bulb1 3
#define bulb2 4
#define bulb3 5
#define bulb4 7

int RECV_PIN = 2;


int itsON[] = {1, 1, 1, 1, 1};

#define code1 55335
#define code2 61455


#define code3 49215
#define code4 39015


IRrecv irrecv(RECV_PIN);
decode_results results;
char temp;
char str[10];
char i = 0;
void setup()
{
  irrecv.enableIRIn();
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(bulb1, OUTPUT);
  pinMode(bulb2, OUTPUT);
  pinMode(bulb3, OUTPUT);
  pinMode(bulb4, OUTPUT);
  digitalWrite(bulb1, HIGH);
  digitalWrite(bulb2, HIGH);
  digitalWrite(bulb3, HIGH);
  digitalWrite(bulb4, HIGH);
  lcd.print(" Minor project ");
  lcd.setCursor(0, 1);
  lcd.print("       on  ");
  delay(2000);
  lcd.clear();
  lcd.print("HOME AUTOMATION ");
  lcd.setCursor(0, 1);
  lcd.print("   USING IR ");
  delay(4000);
  lcd.clear();
  lcd.print("     Project by-");
  lcd.setCursor(0, 1);
  delay(500);
  lcd.print("        Adarsh, Arbaaz, Arjit, Amar        ");
  delay(1000);
   for (int positionCounter = 0; positionCounter < 28; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(400);
  }
  delay(1000);
  lcd.clear();
   lcd.print(" Instruction -     ");
   delay(3000);
   lcd.setCursor(0, 1);
          lcd.print(" Press the button to switch ON/OFF  ");
          delay(1000);
           for (int positionCounter = 0; positionCounter < 24; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(300);
  }
  delay(1000);
  lcd.clear();
  lcd.print("1. Appliance 1");
  lcd.setCursor(0, 1);
  lcd.print("2. Appliance 2");
  delay(3000);
  lcd.clear();
  lcd.print("3. Appliance 3");
  lcd.setCursor(0, 1);
  lcd.print("4. Appliance 4");
  delay(2000);
  lcd.clear();
  delay(500);
}



void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Sensing .");
  delay(500);
  lcd.clear();
  lcd.print("Sensing ..");
  delay(500);
  lcd.clear();
  lcd.print("Sensing ...");
  delay(500);
  lcd.clear();
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    switch (value) {
      case code1:
        if (itsON[1] == 1) {
          digitalWrite(bulb1, LOW);
          itsON[1] = 0;
          lcd.clear();
          lcd.print(" S T A T U S -");
          lcd.setCursor(0, 1);
          lcd.print("Appliance 1 - ON");
          delay(1000);
        }
        else {
          digitalWrite(bulb1, HIGH);
          itsON[1] = 1;
          lcd.clear();
          lcd.print(" S T A T U S -");
          lcd.setCursor(0, 1);
          lcd.print("Appliance 1- OFF");
          delay(1000);
        }
        break;
        
      case code2:
        if (itsON[2] == 1) {
          digitalWrite(bulb2, LOW);
          itsON[2] = 0;
          lcd.clear();
          lcd.print(" S T A T U S -");
          lcd.setCursor(0, 1);
          lcd.print("Appliance 2 - ON");
          delay(1000);
        }
        else {
          digitalWrite(bulb2, HIGH);
          itsON[2] = 1;
          lcd.clear();
          lcd.print(" S T A T U S -");
          lcd.setCursor(0, 1);
          lcd.print("Appliance 2- OFF");
          delay(1000);
        }
        break;
      
      case code3:
        if (itsON[3] == 1) {
          digitalWrite(bulb3, LOW);
          itsON[3] = 0;
          lcd.clear();
          lcd.print(" S T A T U S -");
          lcd.setCursor(0, 1);
          lcd.print("Appliance 3 - ON");
           delay(1000);
        } 
        else {
          digitalWrite(bulb3, HIGH);
          lcd.clear();
          lcd.print(" S T A T U S -");
          itsON[3] = 1;
          lcd.setCursor(0, 1);
          lcd.print("Appliance 3- OFF");
           delay(1000);
        }
        break;
      
      case code4:
     
        if (itsON[4] == 1) {
          digitalWrite(bulb4, LOW);
          lcd.clear();
          lcd.print(" S T A T U S -");
          itsON[4] = 0;
          lcd.setCursor(0, 1);
          lcd.print("Appliance 4 - ON");
           delay(1000);
        }
        else {
          digitalWrite(bulb4, HIGH);
          lcd.clear();
          lcd.print(" S T A T U S -");
          itsON[4] = 1;
          lcd.setCursor(0, 1);
          lcd.print("Appliance 4- OFF");
           delay(1000);
        }
        break;
      default :
      lcd.print("     Press the ");
      lcd.setCursor(0,1);
      lcd.print("   Valid Button");
      
    delay(400);
  }
    Serial.println(value); // you can comment this line
    }
//Serial.println(value); // you can comment this line
    irrecv.resume(); // Receive the next value
  }
