#include "complex_number.h"
#include <stdio.h>

int main()
{
    ComplexNumber *vec = ComplexNumber_create(2, 3);
    ComplexNumber_print(vec);

    ComplexNumber_destroy(&vec);

    return 0;
}