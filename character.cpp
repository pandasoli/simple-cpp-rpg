#include <vector>
#include "./screen.cpp"
#include "./types.cpp"


#ifndef CHARACTER
#define CHARACTER 1

class Character {
private:
  POS old_pos;
  vector<string> old_sprite;

public:
  vector<string> sprite;
  Screen *scr;
  POS pos;

  Character(Screen *scr, vector<string> sprite, POS pos = { 0, 0 }) {
    this->sprite = sprite;
    this->old_sprite = sprite;
    this->scr = scr;
    this->pos = pos;
    this->old_pos = pos;

    this->refresh();
  }

  void refresh() {
    // Cleanipg
    for (int row = 0; row < this->old_sprite.size(); row++)
      for (int col = 0; col < this->old_sprite[row].size(); col++)
        this->scr->buff[this->old_pos.y + row][this->old_pos.x + col] = " ";

    // Drawing
    for (int row = 0; row < this->sprite.size(); row++)
      for (int col = 0; col < this->sprite[row].size(); col++)
        this->scr->buff[this->pos.y + row][this->pos.x + col] = this->sprite[row][col];

    this->old_pos = this->pos;
    this->scr->refresh(); // Refreshing screen
  }

};

#endif

