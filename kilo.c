/*** includes ***/

#include <ctype.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/*** defines ***/
#define CTRL_KEY(k) ((k) & 0x1f)

/*** data ***/

struct termios orig_termios;

/*** terminal ***/

void printAndExit(const char *s)
{
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);
    perror(s);
    exit(1);
}

void disableRawMode(void)
{
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
        printAndExit("tcsetattr");
}

void enableRawMode(void)
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
    raw.c_cc[VMIN] = 0;   // set to 0, so that read returns as soon as there is any input to be read.
    raw.c_cc[VTIME] = 10; // set 1/10 seconds, 100 milliseconds.

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == 1)
        printAndExit("tcsetattr");
}

char editorReadKey(void)
{
    char c;
    int nread;
    while ((nread = read(STDIN_FILENO, &c, 1)) != 1)
    {
        if (nread == -1 && errno != EAGAIN)
            printAndExit("read");
    }
    return c;
}

/*** output ***/
void editorRefreshSceen(void)
{
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);
}

/*** input ***/

void editorProcessKeypress(void)
{
    char c = editorReadKey();

    switch (c)
    {
    case CTRL_KEY('q'):
        write(STDOUT_FILENO, "\x1b[2J", 4);
        write(STDOUT_FILENO, "\x1b[H", 3);
        exit(0);
        break;
    }
}

/*** init ***/

int main(void)
{

    enableRawMode();

    while (1)
    {
        editorRefreshSceen();
        editorProcessKeypress();
    }
    return 0;
}
