#include <termios.h>
#include <unistd.h>

#ifndef KBHIT_H
#define KBHIT_H 1

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_RIGHT 67
#define KEY_LEFT 68
#define KEY_SPACE 32
#define KEY_ENTER 10


struct Keyboard {
private:
  struct termios initial_settings, new_settings;
  int peek_character;

public:
  Keyboard() {
    tcgetattr(0, &initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
    peek_character = -1;
  }

  ~Keyboard() {
    tcsetattr(0, TCSANOW, &initial_settings);
  }

  int kbhit() {
    unsigned char ch;
    int nread;

    if (peek_character != -1) return 1;

    new_settings.c_cc[VMIN] = 0;
    tcsetattr(0, TCSANOW, &new_settings);

    nread = read(0, &ch, 1);

    new_settings.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &new_settings);

    if (nread == 1)
       peek_character = ch;

    return nread == 1 ? 1 : 0;
  }

  int getch() {
    char ch;

    if (peek_character != -1){
      ch = peek_character;
      peek_character = -1;
    }
    else read(0, &ch, 1);

    return ch;
  }
};

#endif

