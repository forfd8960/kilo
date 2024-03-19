## Get window size the hard way

The strategy is to position the cursor at the bottom-right of the screen, then use escape sequences that let us query the position of the cursor. That tells us how many rows and columns there must be on the screen.

```c
if (write(STDOUT_FILENO, "\x1b[999C\x1b[999B", 12) != 12)
    return -1;
```

The C command (Cursor Forward) moves the cursor to the right, and the B command (Cursor Down) moves the cursor down. The argument says how much to move it right or down by.
