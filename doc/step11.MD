## Disable Ctrl-V

```c
raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
```

```sh
❯ ./kilo
22
```

## Step12 Disable Ctrl-M: ICRNL

```c
raw.c_iflag &= ~(ICRNL | IXON);
```

```sh
❯ ./kilo
13
```
