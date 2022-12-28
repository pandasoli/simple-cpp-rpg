#pragma once
#include "../character/character.h"


class Player;

class Enemy : public Character {
public:
  int last_act_time = 0;

  Enemy(
    Screen *scr,
    vector<string> sprite,
    Pos pos = { 0, 0 }
  );

  void onLoop(int i, Player *player);
};

