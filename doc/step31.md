## get window size, the hard way

The `n` command `(Device Status Report)` can be used to query the terminal for status information.
We want to give it an argument of 6 to ask for the cursor position.

- command `\x1b[6n` results

```
27
91 ('[')
51 ('3')
54 ('6')
59 (';')
49 ('1')
51 ('3')
49 ('1')
82 ('R')
```
