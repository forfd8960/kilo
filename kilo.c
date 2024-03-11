/*** includes ***/

#include <ctype.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/*** data ***/

struct termios orig_termios;

/*** terminal ***/

void printAndExit(const char *s)
{
    perror(s);
    exit(1);
}

void disableRawMode()
{
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
        printAndExit("tcsetattr");
}

void enableRawMode()
{
    if (tcgetattr(STDIN_FILENO, &orig_termios) == -1)
        printAndExit("tcgetattr");
    atexit(disableRawMode);

    struct termios raw = orig_termios;
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

    // set a timeout for read, so read() returns if it doesn't get any input for a certain amount of time.
    raw.c_cc[VMIN] = 0;  // set to 0, so that read returns as soon as there is any input to be read.
    raw.c_cc[VTIME] = 1; // set 1/10 seconds, 100 milliseconds.

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == 1)
        printAndExit("tcsetattr");
}

/*** init ***/

int main()
{

    enableRawMode();

    while (1)
    {
        char c = '\0';
        if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN)
            printAndExit("read");
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
