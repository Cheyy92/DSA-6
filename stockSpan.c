#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack{
    int top;
    int *arr;
    int size;
}Stack;

//Function to check if stack is empty
bool isEmpty(Stack *s){
    return s->size == -1;
}

void push(Stack *s, int val){
    s->arr[++s->size] = val;
    s->top = val;
}

void pop(Stack *s){
    if(s->size!=-1){
        printf("%d", s->top);
        s->arr[s->size] = 0;
        s->size--;

    }
    
}

int peek(Stack *s){
    if(s->size !=-1){
        printf("%d", s->arr[s->top]);
    }
}

int size(Stack *s){
    return s->size+1;
}


int main(){
    int n;
    scanf("%d", &n);
    int *prices = (int*)malloc(n *sizeof(int));

    for(int i=0; i<n; i++){
        scanf("%d", &prices[i]);
    }

    for(int i=0; i<n; i++){// go through each price index

        Stack *s = (Stack*)malloc(sizeof(Stack));
        s->size = -1;
        s->arr = (int *)malloc(sizeof(int)*(i+1));

        //Traverse back in the array and push the index to stack if the value is less than or equal to current
        int j=i;
        while(j!=-1){
            if(prices[j]<=prices[i]){
                push(s, j);
                j--;
            }
            
            else{
                break;
            }
        }

        printf("%d ", (s->size)+1);
        free(s->arr);
        free(s);
    }

    return 0;
}