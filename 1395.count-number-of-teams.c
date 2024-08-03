//count-number-of-teams

#include <stdio.h>

int numTeams(int* rating, int ratingSize) {
    int res = 0;

    for (int m = 1; m < ratingSize - 1; m++) {
        int left_smaller = 0, right_larger = 0;

        for (int i = 0; i < m; i++) {
            if (rating[i] < rating[m]) {
                left_smaller++;
            }
        }

        for (int i = m + 1; i < ratingSize; i++) {
            if (rating[i] > rating[m]) {
                right_larger++;
            }
        }

        res += left_smaller * right_larger; // count ascend

        int left_larger = m - left_smaller;
        int right_smaller = ratingSize - m - 1 - right_larger;

        res += left_larger * right_smaller; // count descend
    }

    return res;
}
/*
int main() {
    int rating[] = {2, 5, 3, 4, 1};
    int ratingSize = sizeof(rating) / sizeof(rating[0]);
    
    int result = numTeams(rating, ratingSize);
    printf("Number of valid teams: %d\n", result);
    
    return 0;
}
*/
