#include "../enemy/enemy.h"
#include "./player.h"
#include "../screen.cpp"
#include "../kbhit.cpp"


Player::Player(
  Screen *scr,
  vector<string> sprite,
  Pos pos
) : Character(scr, sprite, 5, pos, false) {
  this->refresh();
}

void Player::refresh() {
  for (int heart = 1; heart < this->lifes + 1; heart++)
    this->scr->buff.at(2).at(3 * heart + 2) = "♥️";

  this->update_screen();
}

void Player::keydown(int key, char ascii, vector<Enemy> *enemies) {
  switch (key) {
    case KEY_RIGHT:
      this->sprite = {
        "@",
        "|\\",
        "|"
      };
      this->cube.x += 2;
      this->cube.w = 2;
      break;

    case KEY_LEFT:
      this->sprite = {
        " @",
        "/|",
        " |"
      };
      this->cube.x -= 2;
      this->cube.w = 2;
      break;

    case KEY_UP:
      this->sprite = {
        " W",
        "/|\\",
        "/ \\"
      };
      this->cube.y -= 1;
      this->cube.w = 3;
      break;

    case KEY_DOWN:
      this->sprite = {
        " M",
        "/|\\",
        "/ \\"
      };
      this->cube.y += 1;
      this->cube.w = 3;
      break;

    case KEY_SPACE:
      break;
   }
}

