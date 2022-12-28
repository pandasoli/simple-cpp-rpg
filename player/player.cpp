#include "../enemy/enemy.h"
#include "./player.h"
#include "../screen.cpp"
#include "../kbhit.cpp"
#include "../libs/libs.h"


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

  string points = inttostr(this->points);
  for (int i = 0; i < points.size(); i++)
    this->scr->buff.at(3).at(5 + i) = points[i];

  this->update_screen();
}

void Player::keydown(int key, char ascii, vector<Enemy> *enemies) {
  switch (key) {
    case KEY_RIGHT:
      this->change_sprite({
        "@",
        "|\\",
        "|"
      });
      this->cube.x += 2;
      break;

    case KEY_LEFT:
      this->change_sprite({
        " @",
        "/|",
        " |"
      });
      this->cube.x -= 2;
      break;

    case KEY_UP:
      this->change_sprite({
        " W",
        "/|\\",
        "/ \\"
      });
      this->cube.y -= 1;
      break;

    case KEY_DOWN:
      this->change_sprite({
        " M",
        "/|\\",
        "/ \\"
      });
      this->cube.y += 1;
      break;

    case KEY_SPACE:
      for (int enemyi = 0; enemyi < enemies->size(); enemyi++) {
        Enemy *enemy = &enemies->at(enemyi);

        if (this->touch(this, enemy)) {
          bool alive = enemy->hit();

          if (!alive) {
            vector<Enemy>::iterator it;
            it = enemies->begin() + enemyi;

            enemy->remove();
            enemies->erase(it);

            this->points += random(1, 3);
          }
        }
      }

      break;
   }
}

