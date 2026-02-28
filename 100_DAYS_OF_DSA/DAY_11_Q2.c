int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    *returnSize = cols;
    *returnColumnSizes = (int*)malloc(cols * sizeof(int));
    
    int** ans = (int**)malloc(cols * sizeof(int*));
    
    for (int i = 0; i < cols; i++) {
        (*returnColumnSizes)[i] = rows;
        ans[i] = (int*)malloc(rows * sizeof(int));
        
        for (int j = 0; j < rows; j++) {
            ans[i][j] = matrix[j][i];
        }
    }
    
    return ans;
}