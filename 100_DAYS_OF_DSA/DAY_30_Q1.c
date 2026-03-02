#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};


struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}


void insertTerm(struct Node** head, int coeff, int exp) {
    
    if (coeff == 0) return; 

    
    if (*head == NULL || (*head)->exp < exp) {
        struct Node* newNode = createNode(coeff, exp);
        newNode->next = *head;
        *head = newNode;
        return;
    }

    
    if ((*head)->exp == exp) {
        (*head)->coeff += coeff;
        return;
    }

    
    struct Node* current = *head;
    while (current->next != NULL && current->next->exp >= exp) {

        if (current->next->exp == exp) {
            current->next->coeff += coeff;
            return; 
        }
        current = current->next;
    }

    
    struct Node* newNode = createNode(coeff, exp);
    newNode->next = current->next;
    current->next = newNode;
}


void printPolynomial(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        
        if (temp->exp == 0) {
            printf("%d", temp->coeff);        
        } else if (temp->exp == 1) {
            printf("%dx", temp->coeff);        
        } else {
            printf("%dx^%d", temp->coeff, temp->exp); 
        }

        
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int n, coeff, exp;

    if (scanf("%d", &n) != 1) return 1;

    for (int i = 0; i < n; i++) {
        if (scanf("%d %d", &coeff, &exp) == 2) {
            insertTerm(&head, coeff, exp);
        }
    }

    printPolynomial(head);

    
    freeList(head);

    return 0;
}