#include <Arduboy.h>
Arduboy arduboy;
int playerwin;
int attempts;
int guessednumber;
int randomnumber;
int upbuffer;
int downbuffer;
int abuffer;
int lastguess;

void setup() {
  arduboy.begin();
  arduboy.clear();
  playerwin = 0;
  attempts = 0;
  guessednumber = 0;
  randomnumber = 0;
  srand(7/8);
  randomnumber = 1 + rand() % 100;
  upbuffer = 0;
  downbuffer = 0;
  abuffer = 0;
  lastguess = 0;
}

void loop() {
  arduboy.clear();
  if( playerwin == 0 ) {
    //Ask the player for a number and play the game
    if( attempts == 7 ) {
      //Game Over screen
      arduboy.setCursor(0, 0);
      arduboy.print("You lost!");
      arduboy.print("\n");
      arduboy.print("Correct Number: ");
      arduboy.print(randomnumber);
      if( arduboy.pressed(A_BUTTON) == true  and abuffer == 0 ) {
        abuffer = 1;
        randomnumber = 1 + rand() % 100;
        attempts = 0;
        playerwin = 0;
      }
    } else {
      //Player has more attempts
      if( arduboy.pressed(UP_BUTTON) == true and upbuffer == 0 ) {
        upbuffer = 1;
        guessednumber = guessednumber + 1;
      }
      if( arduboy.pressed(DOWN_BUTTON) == true and downbuffer == 0 ) {
        downbuffer = 1;
        guessednumber = guessednumber - 1;
      }
      if( arduboy.pressed(A_BUTTON) == true and abuffer == 0 ) {
        abuffer = 1;
        if( guessednumber == randomnumber ) {
          playerwin = 1;
        } else {
          attempts = attempts + 1;
          lastguess = guessednumber;
        }
      }
      arduboy.setCursor(0, 0);
      arduboy.print("Attempt: ");
      arduboy.print(attempts);
      arduboy.print("\n");
      arduboy.print("Number to guess: ");
      arduboy.print(guessednumber);
      arduboy.print("\n");
      if( attempts == 0 ) {
        arduboy.print("Good luck!");
      } else {
        arduboy.print(lastguess);
        if( lastguess > randomnumber ) {
          arduboy.print(" is too high!");
        }
        if( lastguess < randomnumber ) {
          arduboy.print(" is too low!");
        }
      }
    }
  } else {
    //Tell the player that they won!
    arduboy.setCursor(0, 0);
    arduboy.print("You won!");
    arduboy.print("\n");
    arduboy.print("Correct Number: ");
    arduboy.print(randomnumber);
    if( arduboy.pressed(A_BUTTON) == true and abuffer == 0 ) {
      abuffer = 1;
      randomnumber = 1 + rand() % 100;
      attempts = 0;
      playerwin = 0;
    }
  }
  if( arduboy.notPressed(A_BUTTON) == true) {
    abuffer = 0;
  }
  if( arduboy.notPressed(DOWN_BUTTON) == true ) {
    downbuffer = 0;
  }
  if( arduboy.notPressed(UP_BUTTON) == true ) {
    upbuffer = 0;
  }
  arduboy.display();
}
