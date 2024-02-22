#include <stdio.h>

void opera(float *a, float *b)
{
    printf("Recebido: %.2f %.2f\n", *a, *b);
    *a = *a + *b * 3 - 1;
    printf("a alterado em opera: %.2f\n", *a);
}

void proc(float *n, int r)
{
    float w = 0, z = 1.5;
    for (int k = 0; k < r; k++)
    {
        *n += 4.5;
        w++;
        printf("%d %.2f %.2f\n", k, *n, w);
    }
    opera(&w, &z);
    *n = *n + w;
}

int main()
{
    int rep = 2;
    float num = 2.5;
    float x = 8.0, y = 2.5;
    unsigned char n1 = 13, n2 = 20;
    opera(&x, &y);
    printf("Parte 1: %.2f\n", x);
    proc(&num, rep);
    printf("Parte 2: %.2f\n", num);
    printf("Op 1: %d\n", n1 & n2); // bitwise AND operator
    printf("Op 2: %d\n", n1 << 3); // bitwise left shift operator
    printf("Op 3: %d\n", n2 | n1); // bitwise OR operator
    printf("Op 4: %d\n", n2 >> 2); // bitwise right shift operator

    return 0;
}
