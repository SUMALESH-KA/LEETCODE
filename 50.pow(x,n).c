/*double myPow(double x, int n) {
    double a=pow(x,n);
    return a;
}*/

double myPow(double base, int expo) {
    // Handle the base case where expo is 0
    if (expo == 0) {
        return 1.0;
    }
    
    // If expo is INT_MIN, handle it separately
    if (expo == INT_MIN) {
        // Increment expo to INT_MIN + 1 which can be negated safely
        // Then adjust the result by multiplying with base one more time
        expo += 1;
        base = 1 / base;
        return base * myPow(base, -expo);
    }

    // If expo is negative, convert to positive and invert the result
    if (expo < 0) {
        base = 1 / base;
        expo = -expo;
    }
    
    // Initialize result
    double result = 1.0;

    // Exponentiation by squaring method
    while (expo > 0) {
        if (expo % 2 == 1) {
            result *= base;
        }
        base *= base;
        expo /= 2;
    }

    return result;
}
