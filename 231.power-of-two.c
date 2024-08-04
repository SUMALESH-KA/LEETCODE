bool isPowerOfTwo(int n) {
    // Handle non-positive numbers
    if (n <= 0) {
        return false;
    }

    // Continue dividing n by 2 while it's greater than 1
    while (n > 1) {
        if (n % 2 != 0) {
            return false; // Not divisible by 2 means it's not a power of 2
        }
        n /= 2;
    }

    // If n is reduced to 1, it is a power of 2
    return n == 1;
}
