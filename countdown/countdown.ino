#include "LedControl.h"

int DINPin = 12;
int CLKPin = 11;
int CSPin = 10;
int numberOfPanels = 1;
int intensity = 1;
int panelNumber = 0;
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status


  int graphicPanel [8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
  };
    
  int numbers [10][8][4] = { {
  {0, 1, 1, 0},
  {1, 0, 0, 1},
  {1, 0, 0, 1},
  {1, 0, 0, 1},
  {1, 0, 0, 1},
  {1, 0, 0, 1},
  {1, 0, 0, 1},
  {0, 1, 1, 0}
  },
  
 {
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 0},
  {0, 1, 1, 1}
  },
  
{
  {0, 1, 1, 1},
  {0, 0, 0, 1},
  {0, 0, 0, 1},
  {0, 0, 0, 1},
  {1, 1, 1, 1},
  {1, 0, 0, 0},
  {1, 0, 0, 0},
  {1, 1, 1, 1}
  },

{
  {0, 1, 1, 1},
  {0, 0, 0, 1},
  {0, 0, 0, 1},
  {0, 0, 0, 1},
  {0, 1, 1, 1},
  {0, 0, 0, 1},
  {0, 0, 0, 1},
  {0, 1, 1, 1}
  },

{
  {1, 0, 0, 1},
  {1, 0, 0, 1},
  {1, 0, 0, 1},
  {1, 1, 1, 1},
  {0, 0, 0, 1},
  {0, 0, 0, 1},
  {0, 0, 0, 1},
  {0, 0, 0, 1}
  },
  
{
  {1, 1, 1, 0},
  {1, 0, 0, 0},
  {1, 0, 0, 0},
  {1, 0, 0, 0},
  {1, 1, 1, 1},
  {0, 0, 0, 1},
  {0, 0, 0, 1},
  {1, 1, 1, 1}
  },
  
{
  {1, 1, 1, 0},
  {1, 0, 0, 0},
  {1, 0, 0, 0},
  {1, 0, 0, 0},
  {1, 1, 1, 1},
  {1, 0, 0, 1},
  {1, 0, 0, 1},
  {1, 1, 1, 1}
  },
  
{
  {1, 1, 1, 1},
  {1, 0, 0, 1},
  {0, 0, 0, 1},
  {0, 0, 0, 1},
  {0, 0, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 0}
  },
  
{
  {0, 1, 1, 0},
  {1, 0, 0, 1},
  {1, 0, 0, 1},
  {0, 1, 1, 0},
  {0, 1, 1, 0},
  {1, 0, 0, 1},
  {1, 0, 0, 1},
  {0, 1, 1, 0}
  },

{
  {0, 1, 1, 0},
  {1, 0, 0, 1},
  {1, 0, 0, 1},
  {0, 1, 1, 1},
  {0, 0, 0, 1},
  {0, 0, 0, 1},
  {0, 0, 0, 1},
  {0, 1, 1, 1}
  }};
  
  int tempPanel [8] = {0, 0, 0, 0, 0, 0, 0, 0};

LedControl lc=LedControl(DINPin, CLKPin, CSPin, numberOfPanels);

int days = 47;

void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT);     // declare sensor as input
 
  Serial.begin(9600);

  //time_t sometime = now();
  
  lc.shutdown(panelNumber, false);
  lc.setIntensity(panelNumber, intensity);
  lc.clearDisplay(panelNumber);

  display(days);
  
}

void display (int num)
{
  int firstDigit = num / 10;
  int seccondDigit = num % 10;
  
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 4; j++){
      graphicPanel[i][j] = numbers[firstDigit][i][j];
    }
  }

  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 4; j++){
      graphicPanel[i][j+4] = numbers[seccondDigit][i][j];
    }
  }

  for (int i = 0; i <8; i++){
    for (int j = 0; j < 8; j++){
      if(graphicPanel[i][j] == 1){
          lc.setLed(panelNumber, i, j, true);
      }
      else{
        lc.setLed(panelNumber, i, j, false);
      }
    }
  }
}

void blank(){
  for (int i = 0; i <8; i++){
    for (int j = 0; j < 8; j++){
        lc.setLed(panelNumber, i, j, false);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(inputPin);  // read input value
  //Serial.println(val);
  
  if (val == HIGH) 
  {            // check if the input is HIGH
    days = (4096800000 - millis()) / 86400000;
    display(days);
  }
  else {
    blank();
  }
}
