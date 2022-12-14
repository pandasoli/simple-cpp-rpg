#pragma once
#include "../character/character.h"


class Player;
class Enemy : public Character {
public:
  Enemy(
    Screen *scr,
    vector<string> sprite,
    Pos pos = { 0, 0 }
  );

  void onLoop(int i, Player *player);
};

