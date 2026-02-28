#include <stdio.h>

// Added the 'int' return type to the function definition
int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    return a * power(a, b - 1);
}

// Added a main function to test the code
int main() {
    int base = 2;
    int exponent = 5;
    
    int result = power(base, exponent);
    
    printf("%d raised to the power of %d is: %d\n", base, exponent, result);
    
    return 0;
}