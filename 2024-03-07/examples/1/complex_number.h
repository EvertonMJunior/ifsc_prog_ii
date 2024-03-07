typedef struct complex_number ComplexNumber;

ComplexNumber *ComplexNumber_create(float real, float imaginary);
void ComplexNumber_destroy(ComplexNumber **num_ref);
ComplexNumber *ComplexNumber_sum(const ComplexNumber *num1, const ComplexNumber *num2);
ComplexNumber *ComplexNumber_subtract(const ComplexNumber *num1, const ComplexNumber *num2);
ComplexNumber *ComplexNumber_multiply(const ComplexNumber *num1, const ComplexNumber *num2);
ComplexNumber *ComplexNumber_divide(const ComplexNumber *num1, const ComplexNumber *num2);
void ComplexNumber_print(const ComplexNumber *num);