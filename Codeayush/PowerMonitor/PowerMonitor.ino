

////////////////////////////////////////////////////////AYUSH JAIN///////////////////////////

///////////////////////////////////////////////////////REGENERATIVE BREAKING SYSTEM /////////////////

//POWER MONITOR CODE :-

#include "LiquidCrystal.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

float input_voltage = 0.0;
float temp=0.0;
float r1=100000.0;          //100k
float r2=10000.0;           //10k


void setup()
{
   Serial.begin(9600);     //  opens serial port, sets data rate to 9600 bps
   lcd.begin(16, 2);       //// set up the LCD's number of columns and rows: 
   lcd.print("Voltage amount :");
}
void loop()
{

//Conversion formula for voltage
   
    int analog_value = analogRead(A0);  //////////sonam yaha A0 ki jagah A1 kardo 
    temp = (analog_value * 5.0) / 1024.0; 
   input_voltage = temp / (r2/(r1+r2));
   
   if (input_voltage < 0.1) 
   {
     input_voltage=0.0;
   } 
    Serial.print("v= ");
    Serial.println(input_voltage);
    lcd.setCursor(0, 1);
     lcd.print("  ");
    lcd.print(input_voltage);
    lcd.print("   Volts ");
    delay(300);
}
