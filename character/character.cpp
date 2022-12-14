#include <vector>
#include "../screen.cpp"
#include "./character.h"
#include "../types.h"


void Character::update_screen() {
  // Removing old character from screen
  for (int row = 0; row < this->old_cube.h; row++)
    for (int col = 0; col < this->old_cube.w; col++)
      this->scr->buff.at(this->old_cube.y + row).at(this->old_cube.x + col) = " ";

  // Drawing the new one
  for (int row = 0; row < this->cube.h; row++)
    for (int col = 0; col < this->cube.w; col++)
      this->scr->buff.at(this->cube.y + row).at(this->cube.x + col) =
        this->sprite[row].size() - 1 < col
          ? ' '
          : this->sprite[row][col];

  this->old_cube = this->cube;
  this->old_sprite = this->sprite;
  this->scr->refresh();
}

Character::Character(Screen *scr, vector<string> sprite, int lifes, Pos pos, bool autoload) {
  this->scr = scr;
  this->lifes = lifes;

  this->sprite = sprite;
  this->old_sprite = sprite;

  this->cube = {
    pos.x, pos.y,
    0,
    (int) sprite.size()
  };
  this->old_cube = this->cube;

  // Getting sprite width
  for (string row : sprite) {
    if (row.size() > this->cube.w)
      this->cube.w = row.size();
  }

  if (autoload)
    this->refresh();
}

void Character::refresh() {
  this->update_screen();
}

