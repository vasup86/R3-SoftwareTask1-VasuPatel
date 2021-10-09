// C++ code
//
int ledPin =7;
int buzzerPin = 12;

int pinPot = 0;  //Potentiometer Pin

//Left 7-segment display pins, the display is the used for tenth place value
// {input 1, input 2, input 3, input 4}
int tenthPins []= {5,2,3,4};  

//Right 7-segment display, used for the one's place of the value
// {input 1, input 2, input 3, input 4}
int onePins [] = {11,8,9,10};

//[outputNum or decimal number][binaryEquivalent] = pins:(1,2,3,4)
//binary equivalent of the decimal numbers between 0 and 9 stored into 2D Array
int decToBinPreset [10][4] = {{0,0,0,0}, //0 
                      		    {1,0,0,0}, //1
                        	    {0,1,0,0}, //2
                              {1,1,0,0}, //3
                              {0,0,1,0}, //4
                              {1,0,1,0}, //5
                              {0,1,1,0}, //6
                              {1,1,1,0}, //7
                              {0,0,0,1}, //8
                              {1,0,0,1}};//9

void setup()
{
  //set arduino pins related to the decoder input pins as OUTPUT pins
  pinMode(tenthPins[0], OUTPUT);
  pinMode(tenthPins[1], OUTPUT);
  pinMode(tenthPins[2], OUTPUT);
  pinMode(tenthPins[3], OUTPUT);
  pinMode(onePins[0], OUTPUT);
  pinMode(onePins[1], OUTPUT);
  pinMode(onePins[2], OUTPUT);
  pinMode(onePins[3], OUTPUT);
  
  Serial.begin(9600);
  
  //set ledPin and buzzerPin as OUTPUT
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{ 
  //Get the potentiometer value using analogRead 0 to 1023
  int potVal = analogRead(pinPot); 
  
  //map is used to map a number from one bound to its equilavent in other bound
  //analogRead gives value between 0 and 1023, and its converted to its equivalent from 0 to 99.
  potVal = map(potVal, 0,1023,0,99); 
  
  Serial.println(potVal); 
  int tenth = potVal/10; //tenth place value of the potentiometer value by dividing it by 10
  int ones = potVal%10;  //ones place value of the potentiometer value, remainder after closest 10th multiple 
  
  //display the tenth number on the left 7-segment display using displayNumber function
  //displayNumber(tenthValue, left decoder pins)
  displayNumber(tenth, tenthPins);
  delay(50);  //50 ms pause
  
  //display the ones number on the right 7-segment display using displayNumber function
  //displayNumber(onesValue, right decoder pins)
  displayNumber(ones, onePins);
  
  if(potVal >=95){  //if potentiometer value is greater than or equal to 95
  	digitalWrite(ledPin, HIGH);   //LED Pin HIGH (ON)
    tone(buzzerPin, 500);  //buzzer tone at 1000hz
    delay(75);    //75 ms pause
  	digitalWrite(ledPin, LOW);  //LED Pin LOW (OFF)
    noTone(buzzerPin);   //75 ms pause
    delay(75);
  }

  delay(500);
}

void displayNumber(int value, int pins[]){
  // for loop is used to set each pins as HIGH or LOW based on the number
  for (int i=0; i<4; i++){
    //pins[i] = pin#'s from the ith row index of the array
    //decToBinPreset[value][i]: value is the first index (row) which represents the number to be displayed,
    //[i]: represents config for the pin[i], HIGH(1) or LOW(0) based on the number
  	digitalWrite(pins[i], decToBinPreset[value][i]);
  } 
}
