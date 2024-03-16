## Move cursure to top-left position

```
The H command actually takes two arguments: the row number and the column number at which to position the cursor.
```

- `\x1b[H`

The H command actually takes two arguments: the row number and the column number at which to position the cursor.

The default arguments for H both happen to be 1,
so we can leave both arguments out and it will position the cursor at the first row and first column,
as if we had sent the `<esc>[1;1H` command
