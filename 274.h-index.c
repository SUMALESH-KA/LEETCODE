int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);  // Sort in descending order
}

int hIndex(int* citations, int n) {
    qsort(citations, n, sizeof(int), compare);

    int hindex = 0;
    for (int i = 0; i < n; i++) {
        if (citations[i] >= i + 1) {
            hindex = i + 1;
        } else {
            break;
        }
    }

    return hindex;
}