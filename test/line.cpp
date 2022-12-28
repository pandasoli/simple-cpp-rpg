#include <iostream>
#include <vector>
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

