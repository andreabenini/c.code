```
#define WIDTH 32

#define _MAKEDATA(n) data##n
#define MAKEDATA(n) _MAKEDATA(n)

int MAKEDATA(WIDTH) = 7;
int _MAKEDATA(WIDTH) = 8;

int main(int argc, char *argv[]) {
    printf("%d\n", data32);
    return 0;
}
```


Generates the code below, special meaning for the `##` followed by the _n_ parameter

`$ gcc -E foo.c `
```
int data32 = 7;
int dataWIDTH = 8;

int main(int argc, char *argv[]) {
    printf("%d\n", data32);
    return 0;
}
```
