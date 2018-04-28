#include <Arduboy.h>
Arduboy arduboy;

const unsigned char background[] PROGMEM  = {
    0x84, 0x20, 0x9, 0x00, 0x24, 0x00, 0x10, 0x80,
};
const unsigned char player[] PROGMEM  = {
    0xfe, 0x1, 0x3d, 0x25, 0x25, 0x3d, 0x1, 0x1, 0xc1, 0x1, 0x3d, 0x25, 0x25, 0x3d, 0x1, 0xfe, 0x7f, 0x80, 0x9c, 0xbc, 0xb0, 0xb0, 0xb2, 0xb2, 0xb3, 0xb0, 0xb0, 0xb0, 0xbc, 0x9c, 0x80, 0x7f,
};
int playerx = 5;
int playery = 10;

void setup() {
  arduboy.begin();
  arduboy.clear();
}
void loop() {
  arduboy.clear();
  if(arduboy.pressed(LEFT_BUTTON))
    playerx--;
  if(arduboy.pressed(RIGHT_BUTTON))
    playerx++;
  if(arduboy.pressed(UP_BUTTON))
    playery--;
  if(arduboy.pressed(DOWN_BUTTON))
    playery++;
  arduboy.drawBitmap(playerx, playery, player, 16, 16, WHITE);
  for( int backgroundx = 0; backgroundx < 128; backgroundx += 8)
    for( int backgroundy = 0; backgroundy < 64; backgroundy += 8)
      arduboy.drawBitmap( backgroundx, backgroundy, background, 8, 8, WHITE);
  arduboy.display();
}
