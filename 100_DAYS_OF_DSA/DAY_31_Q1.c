#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Define maximum size of the stack

int stack[MAX_SIZE];
int top = -1; // Index of the top element

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top]);
        top--;
    }
}

// Function to display the elements of the stack
void display() {
    if (top == -1) {
        // Based on typical problem statements, an empty stack 
        // usually doesn't output anything on display.
        return; 
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, type, value;

    // Read the number of operations
    if (scanf("%d", &n) != 1) {
        return 1; // Exit if reading fails
    }

    // Process each operation
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &type) != 1) {
             return 1; 
        }

        if (type == 1) {
            if (scanf("%d", &value) != 1) {
                return 1;
            }
            push(value);
        } else if (type == 2) {
            pop();
        } else if (type == 3) {
            display();
        }
    }

    return 0;
}