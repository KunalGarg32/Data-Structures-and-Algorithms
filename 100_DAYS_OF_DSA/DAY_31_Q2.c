#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char * s) {
    int len = strlen(s);
    if (len % 2 != 0) {
        return false; // A valid string must have an even length
    }

    char *stack = (char *)malloc(len * sizeof(char));
    if (!stack) return false; // Allocation check
    
    int top = -1; // Indicates an empty stack

    for (int i = 0; i < len; i++) {
        char current = s[i];

        // If it's an opening bracket, push to stack
        if (current == '(' || current == '{' || current == '[') {
            stack[++top] = current;
        } 
        // If it's a closing bracket, check for matching
        else {
            if (top == -1) { // Stack is empty, meaning no matching opening bracket
                free(stack);
                return false;
            }
            
            char topChar = stack[top--];
            
            if ((current == ')' && topChar != '(') ||
                (current == '}' && topChar != '{') ||
                (current == ']' && topChar != '[')) {
                free(stack);
                return false; // Mismatched bracket
            }
        }
    }

    // If stack is not empty, there are unmatched opening brackets
    bool result = (top == -1); 
    free(stack);
    return result;
}

int main() {
    // Example test cases
    char test1[] = "()";
    char test2[] = "()[]{}";
    char test3[] = "(]";

    printf("Input: \"%s\" -> Output: %s\n", test1, isValid(test1) ? "true" : "false");
    printf("Input: \"%s\" -> Output: %s\n", test2, isValid(test2) ? "true" : "false");
    printf("Input: \"%s\" -> Output: %s\n", test3, isValid(test3) ? "true" : "false");

    return 0;
}