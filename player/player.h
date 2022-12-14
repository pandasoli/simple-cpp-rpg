#pragma once
#include "../character/character.h"


class Enemy;
class Player : public Character {
public:
  Player(
    Screen *scr,
    vector<string> sprite,
    Pos pos = { 0, 0 }
  );

  void refresh();

  void keydown(int key, char ascii, vector<Enemy> *enemies);
};

