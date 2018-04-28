#include <Arduboy.h>
Arduboy arduboy;

int counter;

void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.clear();
  counter = 0;
  arduboy.display();
}

void loop() {
  // put your main code here, to run repeatedly:
  arduboy.clear();
  arduboy.setCursor(0,0);
  if(arduboy.pressed(UP_BUTTON) == true)
    counter++;
  else if (arduboy.pressed(DOWN_BUTTON) == true)
    counter--;
  if( counter == 36 ) {
    
    arduboy.setCursor(30, 30);
    arduboy.print("Yay!");
  }
  //Move the cursor back to the top-left of the screen
  arduboy.setCursor(0, 0);
  arduboy.print(counter);
  arduboy.display();
}
