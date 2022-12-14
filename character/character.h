#pragma once
#include "../screen.cpp"
#include "../types.h"


class Character {
private:
  Cube old_cube;
  vector<string> old_sprite;

protected:
  Screen *scr;

  void update_screen();

public:
  vector<string> sprite;
  Cube cube;
  int lifes;

  Character(Screen *scr, vector<string> sprite, int lifes, Pos pos = { 0, 0 }, bool autoload = true);

  void refresh();
};

