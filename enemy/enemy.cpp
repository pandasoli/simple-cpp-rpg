#include "../character/character.h"
#include "./enemy.h"
#include "../player/player.h"


Enemy::Enemy(
  Screen *scr,
  vector<string> sprite,
  Pos pos
) : Character(scr, sprite, 2, pos, true) {}

void Enemy::onLoop(int i, Player *player) {
  if (i % 100 != 0) return;

}

