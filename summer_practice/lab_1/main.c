#include <stdio.h>
#include "library.h"

int main () {

    int a = 2, b = -3, gc = -99, v = -3, g = -1, j = 2;

    int fv[6] = {2, -3, -99, -3, -1, 2};

    int c = absMinOf(fv, 6);

    printf("%d", c);

    return 0;
}