#include <stdio.h>

int main() {
    int m, n;
    
    
    
    if (scanf("%d %d", &m, &n) != 2) {
        printf("Invalid input for dimensions.\n");
        return 1;
    }
    
    
    int matrix_a[m][n];
    int matrix_b[m][n];
    
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix_a[i][j]);
        }
    }
    
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix_b[i][j]);
        }
    }
    
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            
            printf("%d", matrix_a[i][j] + matrix_b[i][j]);
            
            
            if (j < n - 1) {
                printf(" ");
            }
        }
        
        printf("\n");
    }
    
    return 0;
}