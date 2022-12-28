#include <ctime>
#include <fstream>
#include "../character/character.h"
#include "./enemy.h"
#include "../player/player.h"
#include "../libs/libs.h"


Enemy::Enemy(
  Screen *scr,
  vector<string> sprite,
  Pos pos
) : Character(scr, sprite, 2, pos, true) {}

void Enemy::onLoop(int i, Player *player) {
  if (time(NULL) - this->last_act_time < 2) return;
  this->last_act_time = time(NULL);

  if (this->touch(player, this)) {
    player->hit();
  }
  else {
    vector<Pos> path = makeLine(
      { this->cube.x, this->cube.y },
      { player->cube.x, player->cube.y }
    );

    this->cube.x = path[1].x;
    this->cube.y = path[1].y;
  }
}

