## Trun off all output flag

the `\n` to `\r\n` translation is likely the only output processing feature turned on by default.

- OPOST: turn off all output processing features by turning off the `OPOST` flag.

```c
raw.c_oflag &= ~(OPOST);
```
