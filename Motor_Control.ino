#include <DHT.h>
#define DHTPIN 15
#define DHTTYPE DHT11
int row1 = 13, row2 = 12, row3 = 11, row4 = 10,colum2 = 6, analog_pin = 28, numpad = 0,button1 = 3,autobutton = 14, i =0;
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(autobutton, INPUT_PULLUP);

  pinMode(analog_pin, OUTPUT);

  pinMode(colum2, OUTPUT);

  pinMode(button1, INPUT_PULLUP);

  pinMode(row4, INPUT);

  pinMode(row3, INPUT);

  pinMode(row2, INPUT);

  pinMode(row1, INPUT);

  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int temp = dht.readTemperature();
  if(digitalRead(autobutton) == LOW){
    numpad = 0;
    i += 1;
  }
  else if(digitalRead(button1) == LOW){
    i = 0;
  }
  if(i == 0){
  digitalWrite(colum2, LOW);
  digitalWrite(colum2, HIGH);
  if(digitalRead(row1) == HIGH){
    numpad = 1;
  }
   if(digitalRead(row2) == HIGH){
    numpad = 2;
  }
   if(digitalRead(row3) == HIGH){
    numpad = 3;
  }
   if(digitalRead(row4) == HIGH){
    numpad = 4;
  }
  if(digitalRead(button1) == LOW){
    numpad = 0;
  }
    Serial.println(numpad);
}
else if(i != 0){
    if(temp < 20){
      numpad = 0;
    }
    if(20 < temp && temp < 24){
      numpad = 1;
    }
    if(24 < temp && temp< 28){
      numpad = 2;
    }
    if(28 < temp && temp < 32){
      numpad = 3;
    }
    if(32 < temp){
      numpad = 4;
    }
    Serial.println(numpad);
    Serial.println(temp);
  }
    switch(numpad)
   {
      case 0: analogWrite(analog_pin, 0); break;
      case 1: analogWrite(analog_pin, 80); break;
      case 2: analogWrite(analog_pin, 128); break;
      case 3: analogWrite(analog_pin, 196); break;
      case 4: analogWrite(analog_pin, 255); break;
      }
    delay(1000);
  
  
}

