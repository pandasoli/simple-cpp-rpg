#include <iostream>
#include <sstream>
#include "./libs.h"


int random(int from, int to) {
  return rand() % (to - from + 1) + from;
}

string inttostr(int number) {
  string res;
  stringstream ss;
  ss << number;
  ss >> res;
  return res;
}

