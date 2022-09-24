/**
 * Programmed by  Savdekar
 * Plays the Star Wars main theme whenever the button is pressed
 */
 
// include lcd code
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//pins
int pin = 9; //buzzer
int buttonPin = 8;

//note lengths
int tempo = 1/((120/60)/1000); //120 bpm
int h = 500; //half note
int q = 250; //quarter note
int e = 125; //eighth
int s = 63; //sixteen
int rest = 100;

//notes
//b = sharp
int d4 = 311;
int g4 = 392;
int d5 = 622;
int c4 = 262;
int c5 = 523;
int b4 = 494;
int a4 = 440;
int g5 = 784;
int a4b = 415;
int g4b = 370;
int d5b = 554;
int g5b = 740;
int e4 = 330;
int f4 = 349;
int f5 = 699;
int e5 = 659;

//function to play a tone
//takes in note and the length
void pTone(int note, int length) {
  tone(pin, note);
  delay(length);
  noTone(pin);
  delay(rest);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

//scrolling variables
int stringStart = 0; 
int stringStop = 0;
int scrollCursor = 16;
String title = "Star Wars Main Theme Song";
void loop() {
  lcd.setCursor(0,1);
  lcd.print("   **********   ");
  //makes the title scroll from right to left
  lcd.setCursor(scrollCursor,0);
  lcd.print(title.substring(stringStart,stringStop));
  delay(400);
  lcd.clear();
  if (stringStart == 0 && scrollCursor > 0){
    scrollCursor--;
    stringStop++;
  }
  else if (stringStart == stringStop){
    stringStart = stringStop = 0;
    scrollCursor = 16;
  }
  else if (stringStop == title.length() && scrollCursor == 0){
    stringStart++;
  }
  else{
    stringStart++;
    stringStop++;
  }
  
  //plays song on button press
  if (digitalRead(buttonPin) == LOW)
  {
    lcd.setCursor(0,0);
    lcd.print("    Playing     ");
    pTone(d4, e);
    pTone(d4, e);
    pTone(d4, e);
    pTone(g4b, h);
    pTone(d5b, h);
    pTone(c5, e);
    pTone(b4, e);
    pTone(a4, e);
    pTone(g5b, h);
    pTone(d5, q);
    pTone(c5, e);
    pTone(b4, e);
    pTone(a4, e);
    pTone(g5b, h);
    pTone(d5, q);
    pTone(c5, e);
    pTone(b4, e);
    pTone(c5, e);
    pTone(a4b, h);
    pTone(d4, q);
    pTone(d4, e);
    pTone(g4b, h);
    pTone(d5b, h);
    pTone(c5, e);
    pTone(b4, e);
    pTone(a4, e);
    pTone(g5b, h);
    pTone(d5, q);
    pTone(c5, e);
    pTone(b4, e);
    pTone(a4, e);
    pTone(g5b, h);
    pTone(d5, q);
    pTone(c5, e);
    pTone(b4, e);
    pTone(c5, e);
    pTone(a4b, h);
    pTone(d4, q);
    pTone(d4, e);
    pTone(e4, q);
    pTone(e4, e);
    pTone(c5, e);
    pTone(b4, e);
    pTone(a4, e);
    pTone(g4, e);
    pTone(d5, q);
    pTone(a4b, h);
    pTone(d4, q);
    pTone(d4, e);
  
    pTone(e4, q);
    pTone(e4, e);
    pTone(c5, e);
    pTone(b4, e);
    pTone(a4, e);
    pTone(g4, e);
    pTone(g4, e);
    pTone(a4, e);
    pTone(b4, e);
    pTone(a4, q);
    pTone(e4, e);
    pTone(f4, q);
    pTone(d5, q);
    pTone(d5, e);
    pTone(g5, e);
    pTone(f5, e);
    pTone(e5, e);
    pTone(d5, e);
    pTone(c5, e);
    pTone(b4, e);
    pTone(a4, e);
    pTone(g4, e);
    pTone(d5, h);
    pTone(d4, e);
    pTone(d4, e);
    pTone(d4, e);
    pTone(g5, h);
    pTone(d5, h);
    pTone(c5, e);
    pTone(b4, e);
    pTone(a4, e);
    pTone(g5b, h);
    pTone(d5, q);
    pTone(c5, e);
    pTone(b4, e);
    pTone(a4, e);
    pTone(g5b, h);
    pTone(d5, q);
    pTone(c5, e);
    pTone(b4, e);
    pTone(c5, e);
    pTone(a4b, h);
    pTone(d4, q);
    pTone(d4, e);
    pTone(c5, e);
    pTone(b4, e);
    pTone(c5, e);
    pTone(a4b, h);
    pTone(d5, q);
    pTone(g5, q);
    for (int i = 0; i < 3; i++)
    {
    pTone(g5, e);
    }
    pTone(g5, s);
  }
}
