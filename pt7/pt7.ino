#include <Arduboy.h>
Arduboy arduboy;

int gamestate = 0;
int buffer = 0;
int ballx = 62;
int bally = 0;
int ballsize = 4;
int ballright = 1;
int balldown = 1;
int paddlewidth = 4;
int paddleheight = 9;
int playerx = 0;
int playery = 0;
int computery = 0;
int computerx = 127 - paddlewidth;
int playerscore = 0;
int computerscore = 0;

void setup() {
  arduboy.begin();
  srand(7/8);
  arduboy.setFrameRate(60);
  //Set-up here
  arduboy.clear();
}

void loop() {
  if(!arduboy.nextFrame()) {
    return;
  }
  arduboy.clear();
  arduboy.setCursor(0,0);
  switch( gamestate ){
    case 0:
      arduboy.print("Title Screen");
      if(arduboy.pressed(A_BUTTON) && buffer == 0){
        buffer = 1;
        gamestate = 1;
      }
      break;
    case 1:
      arduboy.setCursor(20,0);
      arduboy.print(playerscore);
      arduboy.setCursor(101,0);
      arduboy.print(computerscore);
      
      arduboy.fillRect(playerx, playery, paddlewidth, paddleheight, WHITE);
      arduboy.fillRect(ballx, bally, ballsize, ballsize, WHITE);
      arduboy.fillRect(computerx, computery, paddlewidth, paddleheight, WHITE);
      
      if(ballright == 1){
        ballx++;
      }else{
        ballx--;
      }
      if(ballx == playerx + paddlewidth && bally + ballsize > playery && bally < playery + paddleheight){
        ballright = 1;
      }
      if(ballx + ballsize == computerx &&  bally + ballsize > computery && bally < computery + paddleheight){
        ballright = -1;
      }
      if(balldown == 1){
        bally++;
      }else{
        bally--;
      }
      if(bally == 0){
        balldown = 1;
      }
      if(bally + ballsize == 63){
        balldown = -1;
      }

      if(ballx < 0){
        ballx = 63;
        computerscore++;
      }else if(ballx > 127){
        ballx = 63;
        playerscore++;
      } 

      if(bally < computery && (rand() % 15 > 0)){
        computery--;
      }
      if(bally > computery && (rand() % 15 > 0)){
        computery++;
      }
      if(playerscore == 1){
        gamestate = 2;
      }else if(computerscore == 1){
        gamestate = 3;  
      }
      if(arduboy.pressed(UP_BUTTON) && playery > 0){
        playery = playery - 1;
      }
      if(arduboy.pressed(DOWN_BUTTON) && playery  + paddleheight < 63){
        playery = playery + 1;
      }
      break;
    case 2:
      arduboy.print("Win Screen");
      if(arduboy.pressed(A_BUTTON) && buffer == 0){
        buffer = 1;
        ballx = 63;
        playerscore = 0;
        computerscore = 0;
        gamestate = 0;
      }
      break;
    case 3:
      arduboy.print("Game Over Screen");
      if(arduboy.pressed(A_BUTTON) && buffer == 0){
        buffer = 1;
        ballx = 63;
        playerscore = 0;
        computerscore = 0;
        gamestate = 0;
      }
      break;
  }
  if(arduboy.notPressed(A_BUTTON))
    buffer = 0;
  //Game code here
  arduboy.display();
}
