#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include "./libs.h"


int random(int from, int to) {
  return rand() % (to - from + 1) + from;
}

int abs(int n) {
  return n < 0 ? -n : n;
}

vector<Pos> makeLine(Pos from, Pos to) {
  const int
    dx = to.x - from.x,
    dy = to.y - from.y,
    len = abs(dx) >= abs(dy) ? abs(dx) : abs(dy),

    delta_x = dx / len,
    delta_y = dy / len;

  int
    x = from.x,
    y = from.y;

  vector<Pos> scheme = {
    { x, y }
  };

  for (int i = 0; i < len; i++) {
    x += delta_x;
    y += delta_y;

    scheme.push_back({ x, y });
  }

  return scheme;
}

string inttostr(int number) {
  string res;
  stringstream ss;
  ss << number;
  ss >> res;
  return res;
}

