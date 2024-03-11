## Disable Ctrl-V

```c
raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
```

```sh
❯ ./kilo
22
```

## Step12 Disable Ctrl-M: ICRNL

- ICRNL: `ICRNL comes from <termios.h>. The I stands for “input flag”, CR stands for “carriage return”, and NL stands for “new line”.`

```c
raw.c_iflag &= ~(ICRNL | IXON);
```

```sh
❯ ./kilo
13
```
