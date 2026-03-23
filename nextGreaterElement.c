#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack{
    int top;
    int *arr;
}Stack;

void push(Stack *s, int val){
    s->arr[++s->top] = val;
}

void pop(Stack *s){
    if(s->top !=-1){
        printf("%d", s->arr[s->top]);
        s->top--;
    }
}

bool isEmpty(Stack *s){
    return s->top != -1;
}

int size(Stack *s){
   return (s->top)+1; 
}

int main(){
    int n;
    scanf("%d", &n);
    int *temps = (int*)malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d", &temps[i]);
    }

    for(int i=0; i<n; i++){
        Stack *s = (Stack*)malloc(sizeof(Stack));
        s->arr = (int*)malloc((n-i-1)*sizeof(int));
        s->top = 0;


        int j=i;
        while(j!=n && temps[j]<=temps[i]){
            push(s, j);
            j++;
        }
        if(j!=n && temps[j]>temps[i]){
            printf("%d ", size(s)-1);
        } else {
            printf("0 ");
        }
        
    }

    return 0;

}
