#include <Arduino.h>
#include "Arglib.h"
#include "ATMlib.h"
#include "bitmaps.h"
#include "song.h"


Arduboy arduboy;
Sprites sprites(arduboy);


void setup() {
  arduboy.start();
  // set the framerate of the game at 60 fps
  arduboy.setFrameRate(60);
  //Initializes ATMSynth and samplerate
  ATM.begin(15625);
  // Begin playback of song.
  ATM.play(music);
  // Lower the tempo ever so slightly
  ATM.tempo(50);
}

void loop() {

  if (!(arduboy.nextFrame())) return;
  arduboy.poll();
  arduboy.clearDisplay();
  for (byte i = 0; i < 4; i++) sprites.drawSelfMasked(32 * i, 10, TEAMarg, i);
  sprites.drawSelfMasked(43, 50, TEAM_argPart5, 0);
  if (arduboy.justPressed(A_BUTTON)) ATM.stop();
  if (arduboy.justPressed(B_BUTTON)) ATM.playPause();
  arduboy.display();
}

