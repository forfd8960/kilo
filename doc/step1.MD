## Main function

```
int main()
{
    return 0;
}
```

```
~/Documents/github/forfd8960/kilo main*
❯ cc kilo.c -o kilo

~/Documents/github/forfd8960/kilo main*
❯ ./kilo

~/Documents/github/forfd8960/kilo main*
❯ echo $?
0
```

## Makefile

```
kilo: kilo.c
		$(CC) kilo.c -o kilo -Wall -Wextra -pedantic -std=c99
```
