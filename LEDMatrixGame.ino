#include "time.h"

int left = 1;
int right = 2;


//initializes starting point of player, the variable keeps track of player location in bottom row
int dot_position = 3;


void PositionController(){
  
  //initializes starting point of player, the variable keeps track of player location

  //Read buttons and act on it
  if (digitalRead(left) = HIGH & dot_position > 0){
    digitalWrite(dot_position + 3, LOW);
    dot_position = dot_position - 1;
    digitalWrite(dot_position + 3, HIGH);
  }
   
  if (digitalRead(right) = HIGH & dot_position < 4){
    digitalWrite(dot_position + 3, LOW);
    dot_position = dot_position + 1;
    digitalWrite(dot_position + 3, HIGH);
  }
  
}

void setup() {
    Serial.begin(9600);
  
    //The left and right control buttons
    pinMode(left, INPUT);
    pinMode(right, INPUT);
    
    // Display LEDs //
    pinMode(3, OUPTUT);
    pinmode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
  
}

void loop() {
  // Generate random number
  
  // Print desired position to Serial
  Serial.println(correct_position);
  PositionController();

  // I have to somehow make PositionController() run continuously
  delay(1000);
  if (button_position == correct_position){
    Serial.println(" ")
  }
  else {
    Serial.println("You failed")
    break;
  }
  
}
