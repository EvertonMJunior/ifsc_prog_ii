#include "complex_number.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// types from complex_number.h
// typedef struct complex_number ComplexNumber;

// ComplexNumber *ComplexNumber_create(float real, float imaginary);
// void ComplexNumber_destroy(ComplexNumber **num_ref);
// ComplexNumber *ComplexNumber_sum(const ComplexNumber *num1, const ComplexNumber *num2);
// ComplexNumber *ComplexNumber_subtract(const ComplexNumber *num1, const ComplexNumber *num2);
// ComplexNumber *ComplexNumber_multiply(const ComplexNumber *num1, const ComplexNumber *num2);
// ComplexNumber *ComplexNumber_divide(const ComplexNumber *num1, const ComplexNumber *num2);
// void ComplexNumber_print(const ComplexNumber *num);

// Implementation

struct complex_number {
    float real;
    float imaginary;
};

ComplexNumber *ComplexNumber_create(float real, float imaginary) {
    ComplexNumber *num = malloc(sizeof(ComplexNumber));
    num->real = real;
    num->imaginary = imaginary;
    return num;
}

void ComplexNumber_destroy(ComplexNumber **num_ref) {
    free(*num_ref);
    *num_ref = NULL;
}

void ComplexNumber_print(const ComplexNumber *num) {
    printf("%f + %fi\n", num->real, num->imaginary);
}