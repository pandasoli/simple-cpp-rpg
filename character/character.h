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
  Cube cube;
  unsigned int lifes;
  vector<string> sprite;

  Character(Screen *scr, vector<string> sprite, unsigned int lifes, Pos pos = { 0, 0 }, bool autoload = true);

  void remove();
  bool hit();
  void refresh();
  bool touch(Character *a, Character *b);

  void change_sprite(vector<string> sprite);
};

