#include <vector>
#include <ctime>
#include "./screen.cpp"
#include "./kbhit.cpp"
#include "./enemy/enemy.h"
#include "./player/player.h"
#include "./libs/libs.h"

using namespace std;


int main(void) {
  Screen scr;
  Keyboard kb;
  Player player (
    &scr,
    {
      " M",
      "/|\\",
      "/ \\"
    },
    { 30, 13 }
  );

  int loop_times = 0;
  vector<Enemy> enemies;
  int last_enemy_secs = -1;

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
    if (time(NULL) - last_enemy_secs >= 6) {
      Enemy enemy (
        &scr,
        {
          " <",
          "/\\\\"
        },
        {
          random(0, scr.buff.at(0).size() - 1),
          random(0, scr.buff.size() - 1)
        }
      );

      enemies.push_back(enemy);
      last_enemy_secs = time(NULL);
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
