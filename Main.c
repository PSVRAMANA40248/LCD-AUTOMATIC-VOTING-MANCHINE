#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int button1 = 7;
const int button2 = 8;

int votes1 = 0;
int votes2 = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Voting Machine");
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  delay(2000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("A: ");
  lcd.print(votes1);
  lcd.print("  B: ");
  lcd.print(votes2);

  if (digitalRead(button1) == HIGH) {
    votes1++;
    lcd.setCursor(0, 1);
    lcd.print("Voted for A      ");
    delay(1000);
  }

  if (digitalRead(button2) == HIGH) {
    votes2++;
    lcd.setCursor(0, 1);
    lcd.print("Voted for B      ");
    delay(1000);
  }

  lcd.setCursor(0, 1);
  lcd.print("Vote Now         ");
}
