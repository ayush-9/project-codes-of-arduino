/* 
 *  ***************************************************************-------------MADE BY AYUSH JAIN-----------------------------*****************************************************************
The circuit:
* LCD RS pin to digital pin 12
* LCD Enable pin to digital pin 11
* LCD D4 pin to digital pin 5
* LCD D5 pin to digital pin 4
* LCD D6 pin to digital pin 3
* LCD D7 pin to digital pin 2
* LCD R/W pin to ground
* 10K resistor:
* ends to +5V and ground
* wiper to LCD VO 
* trigPin = 7  pin 7
* echoPin = 6  pin 6
* myservo for openig / closing pin 8
* test0 for wet pin 10
* test1 for dry pin 9int Buzzer = A0; 
int obstaclePin0 = A1;  // This is our input pin
int obstaclePin1 = A2;  // This is our input pin
int hasObstacle0 = HIGH;  // HIGH MEANS NO OBSTACLE
int hasObstacle1 = HIGH;  // HIGH MEANS NO OBSTACLE
*/

#include <Servo.h>
#include <LiquidCrystal.h> 

// initialize the library with the numbers of the interface pins

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// These constants won't change. They're used to give names
// to the pins used:

const int analogInPin = A5; // Analog input pin that the Sensor is attached to
int sensorValue = 0; // value read from the garbage Moisture
int pos = 25; 
int percent = 0;

Servo servo_test0;
Servo servo_test1;

Servo myservo; 
const int trigPin = 7;
const int echoPin = 6;
long duration;
float distance;

int Buzzer = A0; 
int obstaclePin0 = A1;  // This is our input pin
int obstaclePin1 = A2;  // This is our input pin
int hasObstacle0 = HIGH;  // HIGH MEANS NO OBSTACLE
int hasObstacle1 = HIGH;  // HIGH MEANS NO OBSTACLE
  


void setup() {

  pinMode(Buzzer, OUTPUT);
  pinMode(obstaclePin0, INPUT);
  pinMode(obstaclePin1, INPUT);
   
 
 myservo.attach(8);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT); 
  
 myservo.write(pos);

// set up the LCD's number of columns and rows:

 servo_test0.attach(10);
 servo_test1.attach(9); 

 servo_test0.write(80);
 servo_test1.write(pos);

 lcd.begin(16, 2);
 lcd.print("                Smart");
 // scroll 13 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(300);
  }
  lcd.clear();
  lcd.setCursor(0, 1);
   lcd.print("    Dustbin    ");
  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(300);
  }
   lcd.clear();
   lcd.print("     Smart");
  lcd.setCursor(0, 1);
 lcd.print("    Dustbin    ");
  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  delay(2000);
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(200);
  }
   lcd.clear();
  lcd.setCursor(0, 1);
 lcd.print(" Keep your country clean  ");
  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 25; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(250);
  }
 delay(1000);
} 





void loop() {


  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = 0.034*(duration/2);
  Serial.println(distance);
 
  
  if (distance < 60)
    {
   
      lcd.clear();
      lcd.print("Dustbin Status - ");
    delay(200);
    lcd.setCursor(0,1);
    lcd.print("     Open     ");
      myservo.write(pos+160);
      delay(2000);
      lcd.clear();
      lcd.print("Drop the garbage");
      delay(3000);
      lcd.clear();
       lcd.print("Moisture contnt:");
      sensorValue = analogRead(analogInPin);// read the analog in value:
      percent = convertToPercent(sensorValue);
        delay(1000);
      lcd.setCursor(0, 1);
      lcd.print(percent);
        // wait 300 milliseconds before the next loop for the 
        //analog-to-digital converter to settle after the last reading:
        delay(300);
        
         if (percent >= 6 )
        
          { 
            delay(500);
           lcd.clear();
           lcd.print("WET Garbage");
             delay(500);
           servo_test0.write(-160);                   //command to rotate the servo to the specified angle 
             delay(2000);   
           servo_test0.write(80);
      
          } 
       else
          {
            delay(1000);
           lcd.clear();
           lcd.print("DRY Garbage");
               delay(1500);
           servo_test1.write(70);                   //command to rotate the servo to the specified angle 
               delay(2000);   
           servo_test1.write(pos);
     
          }

          
   }

  else 
  
  {
    myservo.write(pos);
    delay(50);
    lcd.clear();
    lcd.print("Dustbin Status - ");
    delay(200);
    lcd.setCursor(0,1);
    lcd.print("     Closed     ");
    delay(2000);
//  hasObstacle0 = digitalRead(obstaclePin0); //Reads the output of the obstacle sensor from the 7th PIN of the Digital section of the arduino
//  hasObstacle1 = digitalRead(obstaclePin1);
//
// if (hasObstacle0 == LOW && hasObstacle1 == LOW ) //LOW means something is ahead, so illuminates the 13th Port connected LED
//  {
//    digitalWrite(Buzzer, HIGH);//Illuminates the 13th Port LED
//    lcd.clear();
//    lcd.print("BOTH are full");
//    delay(3000);
//  }
//  
//  else if (hasObstacle0 == LOW ) //LOW means something is ahead, so illuminates the 13th Port connected LED
//  {
//    digitalWrite(Buzzer, HIGH);//Illuminates the 13th Port LED
//    lcd.clear();
//    lcd.print("WET side is full");
//    delay(3000);
//  }
//  else  if (hasObstacle1 == LOW ) //LOW means something is ahead, so illuminates the 13th Port connected LED
//  {
//    digitalWrite(Buzzer, HIGH);//Illuminates the 13th Port LED
//    lcd.clear();
//    lcd.print("Dry side is full");
//    delay(3000);
//  }
//  else
//  {
//    
//    digitalWrite(Buzzer, LOW);
//  }
//  delay(200);

     lcd.clear();
    lcd.print("Swachh  Bharat  Abhiyan");
     for (int positionCounter = 0; positionCounter < 23; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(250);
     }
    lcd.clear();
    lcd.print("Project    by ");
    lcd.setCursor(0, 1);
    lcd.print("Ayush Jain EC-A");
    delay(1000);    

  }
  
      delay(300);

}

   
   
int convertToPercent(int value)
{
  int percentValue = 0;
  percentValue = map(value, 1023, 465, 0, 100);
  return percentValue;
}
