## Error handling

- `perror()` looks at the global errno variable and prints a descriptive error message for it

- `tcsetattr(), tcgetattr(), and read()` all return -1 on failure, and set the errno value to indicate the error.

```sh
❯ echo test | ./kilo
tcgetattr: Inappropriate ioctl for device

```
