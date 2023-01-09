#include "time.h"

int left = 5;
int right = 3;


//initializes starting point of player, the variable keeps track of player location in bottom row
int button_position = 3;


void PositionController(){
  
  //initializes starting point of player, the variable keeps track of player location in bottom row
  int button_position = 3;

  //Read buttons and act on it
  if (digitalRead(left) = LOW & button_position > 0){
    button_position = button_position - 1;
  }
   
  if (digitalRead(right) = LOW & button_position < 7){
    button_position = button_position + 1;
  }

  setLed(0, 7, button_position, true);
}

void setup() {
    Serial.begin(9600);

}

void loop() {
  /* Generate random number*/
  
  Serial.println(correct_position);
  PositionController();

  /* I have to somehow make PositionCOntroller() run continuously*/
  delay(1000);
  if (button_position == correct_position){
    Serial.println(" ")
  }
  else {
    Serial.println("You failed")
    break;
  }
  
}
