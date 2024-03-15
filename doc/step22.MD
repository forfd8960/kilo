## Refresh Sceen

```
Escape sequences always start with an escape character (27) followed by a [ character. Escape sequences instruct the terminal to do various text formatting tasks, such as coloring text, moving the cursor around, and clearing parts of the screen.
```

In C, `\x1b[2J` is an escape sequence that is used to clear the screen in a terminal or console window. This escape sequence is a combination of special characters that, when printed to the terminal, instruct the terminal to clear the screen.

Here's a breakdown of what each part of \x1b[2J represents:

- `\x1b`: This is the escape character in C, which is represented by the hexadecimal value 0x1b. It is used to signal the terminal that what follows is a control sequence.
- `[`: This character is used to start the control sequence.
- `2J`: This part of the control sequence specifically instructs the terminal to clear the entire screen.
