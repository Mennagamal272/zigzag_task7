#include<LiquidCrystal.h>
#include<Keypad.h>

LiquidCrystal lcd(12,11,A0,A1,A2,A3);

const byte ROWS = 4;
const byte COLS = 4;
byte row[ROWS] = {9, 8, 7, 6};
byte col[COLS] = {5, 4, 3, 2};
char keys[ROWS][COLS] = {{'1','2','3','A'},
            {'4','5','6','B'},
            {'7','8','9','C'},
            {'*','0','#','D'}};

Keypad keypad = Keypad(makeKeymap(keys),row,col,ROWS,COLS);

void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop()
{
  char key = keypad.getKey();
  if(key){
    lcd.setCursor(0,0);
    lcd.print(key);
    Serial.print(key);
  }
}
