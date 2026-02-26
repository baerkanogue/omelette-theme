// omelette
#include <stdio.h>

int square(int x) { return x * x; }

struct Point { int x, y; };

int main() {
    int i = 5;
    float f = 3.14;
    char c = 'A';

    struct Point p = {1,2};

    for (i = 0; i < 2; i++)
        printf("%d %s\n", i, (i % 2 == 0) ? "even" : "odd");

    printf("%d\n", square(4));
    return 0;
}