// reverse a integer

#include <stdio.h>
#include <limits.h> // For INT_MAX and INT_MIN
#include <math.h>   // For pow (although it's not needed for this problem)

// Function to reverse an integer
int reverse(int x) {
    long reversed = 0; // Use long to handle overflow during reversal
    
    while (x != 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x = x / 10;
    }

    // Check for overflow before returning the result
    if (reversed > INT_MAX || reversed < INT_MIN) {
        return 0;
    }

    return (int)reversed; // Cast back to int if within bounds
}

int main() {
    int num = 123;
    int result = reverse(num);
    printf("Reversed number: %d\n", result); // Output: 321

    num = -123;
    result = reverse(num);
    printf("Reversed number: %d\n", result); // Output: -321

    num = 1534236469;
    result = reverse(num);
    printf("Reversed number: %d\n", result); // Output: 0 (due to overflow)

    return 0;
}
