#include <iostream>
#include <vector>
#include "./screen.cpp"
#include "./kbhit.cpp"
#include "./enemy/enemy.h"
#include "./player/player.h"

using namespace std;


int random(int from, int to) {
  return rand() % (to - from + 1) + from;
}

int main(void) {
  Screen scr;
  Keyboard kb;
  Player player (
    &scr,
    {
      " O",
      "/|\\",
      "/ \\"
    },
    { 30, 10 }
  );

  int loop_times = 0;
  vector<Enemy> enemies;

  while (true) {
    // Sending keys to make player moves
    if (kb.kbhit()) {
      int key = kb.getch();
      if (key == 0 || key == 0xe0) key = kb.getch();

      char ascii = key;
      if (ascii == 'q') break;

      player.keydown(key, ascii, &enemies);
      player.refresh();
    }

    // Creating enemies
    if (loop_times % 200 == 0) {
      Enemy enemy (
        &scr,
        {
          " O",
          "/\\\\"
        },
        {
          random(0, scr.buff.at(0).size() - 1),
          random(0, scr.buff.size() - 1)
        }
      );

      enemies.push_back(enemy);
    }

    // Updating enemies
    for (Enemy enemy : enemies) {
      enemy.onLoop(loop_times, &player);
      enemy.refresh();
    }

    // Going to the next loop
    loop_times++;
  }

  return 0;
}
