#include<cstdlib>

//Gotta fix position issues (+3 stuff) and see if rand() generates reals or integers.

const int left = 1;
const int right = 2;

//initializes starting point of player, the variable keeps track of player location in LED row
int dot_position = 3;

void PositionController(){
  //Read buttons and act on it
  if (digitalRead(left) == HIGH && dot_position > 0){
    digitalWrite(dot_position + 2, LOW);
    dot_position = dot_position - 1;
    digitalWrite(dot_position + 2, HIGH);
  } 
  if (digitalRead(right) == HIGH && dot_position < 4){
    digitalWrite(dot_position + 2, LOW);
    dot_position = dot_position + 1;
    digitalWrite(dot_position + 2, HIGH);
  }
}

int current_time;
int cp;

//Generate correct position.
int PositionGenerator(){
  srand(analogRead(0));
  int correct_position = rand() % 6;
  current_time = millis();
  return correct_position;
}

void setup() {
    Serial.begin(9600);
  
    //The left and right control buttons
    pinMode(left, INPUT);
    pinMode(right, INPUT);
    
    // Display LEDs //
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
  
    digitalWrite(3, HIGH);
  
    // Generate correct position for first time
    cp = PositionGenerator();
    // Print desired position to Serial for first time
    Serial.println(cp);
  
}

void loop() {
  // Checks if at least 100 ms (1 s) has passed since the correct position has been sent to serial
  if (millis() - current_time >= 1000){
    if (dot_position == cp){
      cp = PositionGenerator();
      Serial.println(cp);
    }
    else {
      Serial.println("You failed");
      break;
    }    
  }
  else {
    PositionController();
  }
    
}
