int** transpose(int** matrix, int matrixRowSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    // Allocate memory for the result matrix
    int** result = malloc(*matrixColSize * sizeof(int*));
    *returnSize = *matrixColSize;
    *returnColumnSizes = malloc(*matrixColSize * sizeof(int));
    
    // Transpose the matrix
    for (int i = 0; i < *matrixColSize; i++) {
        (*returnColumnSizes)[i] = matrixRowSize;
        result[i] = malloc(matrixRowSize * sizeof(int));
        for (int j = 0; j < matrixRowSize; j++) {
            result[i][j] = matrix[j][i];
        }
    }
    
    return result;
}