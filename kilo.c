#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

struct termios orig_termios;

void disableRawMode()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode()
{
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);

    struct termios raw = orig_termios;
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

    // set a timeout for read, so read() returns if it doesn't get any input for a certain amount of time.
    raw.c_cc[VMIN] = 0;  // set to 0, so that read returns as soon as there is any input to be read.
    raw.c_cc[VTIME] = 1; // set 1/10 seconds, 100 milliseconds.

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main()
{
    enableRawMode();

    char c = '\0';
    read(STDIN_FILENO, &c, 1);
    while (1)
    {
        if (iscntrl(c))
        {
            printf("%d\r\n", c);
        }
        else
        {
            printf("%d (%c)\r\n", c, c);
        }
        if (c == 'q')
            break;
    }
    return 0;
}
