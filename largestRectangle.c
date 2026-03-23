#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100000

// Stack to store indices
int stack[MAX_SIZE];
int top = -1;

// Function to push an element to stack
void push(int value) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = value;
    }
}

// Function to pop an element from stack
int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

// Function to peek top of stack
int peek() {
    if (top >= 0) {
        return stack[top];
    }
    return -1;
}

// Function to check if stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to find the largest rectangle in histogram using stack
int largestRectangleArea(int* heights, int heightsSize) {
    if (heightsSize == 0) {
        return 0;
    }
    
    int maxArea = 0;
    
    // Process each bar in the histogram
    for (int i = 0; i < heightsSize; i++) {
        // Pop bars and calculate areas while current bar is smaller
        // than the bar at the top of stack
        while (!isEmpty() && heights[i] < heights[stack[top]]) {
            int h_idx = pop();          // Index of the bar to be removed
            int height = heights[h_idx]; // Height of the removed bar
            
            // Calculate width: from the bar after the new top to current bar
            // If stack is empty, width is from index 0 to current
            int width = isEmpty() ? i : (i - stack[top] - 1);
            
            int area = height * width;
            if (area > maxArea) {
                maxArea = area;
            }
        }
        
        // Push current bar index to stack
        push(i);
    }
    
    // Pop remaining bars from stack and calculate area
    while (!isEmpty()) {
        int h_idx = pop();
        int height = heights[h_idx];
        
        // Width extends to the end of histogram
        int width = isEmpty() ? heightsSize : (heightsSize - stack[top] - 1);
        
        int area = height * width; 
        if (area > maxArea) {
            maxArea = area;
        }
    }
    
    return maxArea;
}

// Main function with test cases
int main() {
    printf("=== Largest Rectangle in Histogram ===\n\n");
    
    // Test Case 1: [2, 1, 5, 6, 2, 3]
    int heights1[] = {2, 5, 6, 2, 3};
    int size1 = 5;
    int result1 = largestRectangleArea(heights1, size1);
    printf("Largest Rectangle Area: %d\n", result1);
    
    
    
    return 0;
}

