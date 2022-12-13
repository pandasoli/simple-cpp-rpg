#include <iostream>
#include "./screen.cpp"
#include "./character.cpp"

using namespace std;


int main(void) {
  Screen scr;
  Character player (
    &scr,
    {
      " O",
      "/|\\",
      "/ \\"
    }
  );
  

  return 0;
}

