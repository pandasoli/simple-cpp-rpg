#include <vector>
#include "../screen.cpp"
#include "./character.h"
#include "../types.h"


void Character::update_screen() {
  this->remove();

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

void Character::remove() {
  for (int row = 0; row < this->old_cube.h; row++)
    for (int col = 0; col < this->old_cube.w; col++)
      this->scr->buff.at(this->old_cube.y + row).at(this->old_cube.x + col) = " ";
}

// return if the character is alive or not
bool Character::hit() {
  this->lifes--;

  if (this->lifes == 0)
    this->remove();

  return this->lifes != 0;
}

void Character::change_sprite(vector<string> sprite) {
  this->sprite = sprite;
  this->cube.h = sprite.size();

  for (string row : sprite)
    if (row.size() > this->cube.w)
      this->cube.w = row.size();
}

Character::Character(Screen *scr, vector<string> sprite, unsigned int lifes, Pos pos, bool autoload) {
  this->scr = scr;
  this->lifes = lifes;

  this->cube = { pos.x, pos.y, 0, 0 };
  this->old_cube = this->cube;

  this->change_sprite(sprite);
  this->old_sprite = sprite;

  if (autoload)
    this->refresh();
}

void Character::refresh() {
  this->update_screen();
}

bool Character::touch(Character *a, Character *b) {
  return !(
    ((a->cube.y + a->cube.h) < (b->cube.y)) ||
    (a->cube.y > (b->cube.y + b->cube.h)) ||
    ((a->cube.x + a->cube.w) < b->cube.x) ||
    (a->cube.x > (b->cube.x + b->cube.w))
  );
}

