#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int m = matrixSize;
    int n = matrixColSize[0];
    *returnSize = m * n;
    
    int* ans = (int*)malloc((*returnSize) * sizeof(int));
    
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    int idx = 0;
    
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            ans[idx++] = matrix[top][i];
        }
        top++;
        
        for (int i = top; i <= bottom; i++) {
            ans[idx++] = matrix[i][right];
        }
        right--;
        
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans[idx++] = matrix[bottom][i];
            }
            bottom--;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans[idx++] = matrix[i][left];
            }
            left++;
        }
    }
    
    return ans;
}