#include <stdio.h>

int main() {
    int n;
    
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    int isIdentity = 1;
    int val;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &val);
            
            if (i == j && val != 1) {
                isIdentity = 0;
            } else if (i != j && val != 0) {
                isIdentity = 0;
            }
        }
    }

    if (isIdentity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }

    return 0;
}