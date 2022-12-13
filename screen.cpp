#include <err.h>       // err
#include <fcntl.h>     // open
#include <unistd.h>    // close
#include <stdlib.h>
#include <sys/ioctl.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

#ifndef SCREEN
#define SCREEN 1

class Screen {
private:
  winsize get_size() {
    winsize ws;
    int fd;

    fd = open("/dev/tty", O_RDWR);

    if (fd < 0 || ioctl(fd, TIOCGWINSZ, &ws) < 0)
      err(8, "/dev/tty");

    close(fd);
    return ws;
  }

public:
  /*
   This is string and but char because characters like ╔═║╝╗╚
   and emojis are more when one char. Ex: 😊 is '\uD83D' plus '\uDE0A'.
  */
  vector<vector<string>> buff;

  Screen() {
    winsize screen_size = this->get_size();
    this->buff.resize(screen_size.ws_row);

    for (int row = 0; row < screen_size.ws_row; row++) {
      vector<string> cols;

      for (int col = 0; col < screen_size.ws_col; col++)
        cols.push_back(" ");

      this->buff.push_back(cols);
    }
  }

  void refresh() {
    cout << "\033[0;0f";

    for (vector<string> row : this->buff) {
      for (string col : row)
        cout << col;

      cout << endl;
    }
  }

};

#endif

