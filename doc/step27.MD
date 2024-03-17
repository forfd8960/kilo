## Get Window Size

- `ioctl`:

On success, `ioctl()` will place the number of columns wide and the number of rows high the terminal is into the given winsize struct. On failure, ioctl() returns -1.
