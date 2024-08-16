
int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int maxDistance(int** arr, int arraysSize, int* arraysColSize) {
    int min_val = arr[0][0];
    int max_val = arr[0][arraysColSize[0] - 1];
    int result = 0;

    for (int i = 1; i < arraysSize; i++) {
        int cur_min = arr[i][0];
        int cur_max = arr[i][arraysColSize[i] - 1];

        int distance1 = abs(cur_max - min_val);
        int distance2 = abs(max_val - cur_min);

        result = max(result, max(distance1, distance2));

        min_val = min(min_val, cur_min);
        max_val = max(max_val, cur_max);
    }
    return result;
}
