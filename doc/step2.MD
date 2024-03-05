# Enter Raw Mode

## canonical mode

> However, by default your terminal starts in canonical mode, also called cooked mode. In this mode, keyboard input is only sent to your program when the user presses Enter

## disable ECHO

- `ECHO`: The ECHO feature causes each key you type to be printed to the terminal, so you can see what you’re typing.

* `tcgetattr`: Terminal attributes can be read into a termios struct by `tcgetattr()`
* `tcsetattr`: After modifying them, you can then apply them to the terminal using `tcsetattr()`.
* `TCSAFLUSH`: The `TCSAFLUSH` argument specifies when to apply the change: in this case, it waits for all pending output to be written to the terminal, and also discards any input that hasn’t been read.

* `atexit`: register `disableRawMode()` function to be called automatically when the program exits
* `c_lflag`: local flag.
* `c_iflag`: input flag.
* `c_oflag`: output flag.
* `c_cflag`: control flag.

```c
struct termios raw = orig_termios;
raw.c_lflag &= ~(ECHO);

tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
```
