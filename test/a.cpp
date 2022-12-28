#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

struct pos {
  int x, y;
};

int abs(int n) {
  return n < 0 ? -n : n;
}

vector<pos> makeLine(pos from, pos to) {
  const int
    dx = to.x - from.x,
    dy = to.y - from.y,
    len = abs(dx) >= abs(dy) ? abs(dx) : abs(dy),

    delta_x = dx / len,
    delta_y = dy / len;

  int
    x = from.x,
    y = from.y;

  vector<pos> scheme = {
    { x, y }
  };

  for (int i = 0; i < len; i++) {
    x += delta_x;
    y += delta_y;

    scheme.push_back({ x, y });
  }

  return scheme;
}


int main(void) {
  const pos objective = { 3, 3 };
  pos iam = { 10, 12 };

  while (objective.x != iam.x && objective.y != iam.y) {
    vector<pos> line = makeLine(
      iam,
      objective
    );

    printf("\033[%d;%df ", iam.y, iam.x);

    iam.x = line[1].x;
    iam.y = line[1].y;

    printf("\033[%d;%df.", iam.y, iam.x);
    sleep(1);
  }

  printf("\033[20;0f");

  return 0;
}

