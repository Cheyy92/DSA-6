//Given an array of N integers.
//Find the sum of the minimum elements of every possible contiguous subarray.
//Solve in O(N) time using stack.

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct{
    int data[MAX];
    int top;
}Stack;

void push(Stack *s, int val){
    s->data[++s->top] = val;
}

int pop(Stack *s){
    return s->data[(s->top)--];
}

int peek(Stack *s){
    return s->data[s->top];
}

int isEmpty(Stack*s){
    return s->top == -1;
}

int main(){
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int left[MAX];
    int right[MAX];

    static Stack s;
    s.top=-1;

    //fill left[] : distance to previous STRICTLY SMALLER element
    for(int i=0; i<n; i++){
        while(!isEmpty(&s) && arr[peek(&s)] >= arr[i]){
            pop(&s); //pop if previous element is larger than or equal to curr
        }

        left[i] = isEmpty(&s)? (i+1) : (i-peek(&s));
        push(&s, i);
    }

    s.top=-1; //reset stack

    //fill right[]: distance to the next SMALLER or EQUAL element
    for(int i=n-1; i>=0; i--){
        while(!isEmpty(&s) && arr[peek(&s)] > arr[i]){
            pop(&s);
        }

        right[i] = isEmpty(&s)?(n-i) : (peek(&s) - i);
        push(&s, i);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans += arr[i]*left[i]*right[i];
    }

    printf("%d", ans);
    return 0;

}