#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct Stack{
    int top;
    int arr[MAX];
}Stack;

void push(Stack *s, int val){
    s->arr[++s->top] = val;
}

int pop(Stack *s){
    return s->arr[s->top--];
}

int peek(Stack *s){
    return s->arr[s->top];
}

int isEmpty(Stack *s){
    return s->top==-1;
}

int main(){
    int n;
    scanf("%d", &n);
    int *sequence1 = (int*)malloc(n * sizeof(int));
    int *sequence2 = (int*)malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d", &sequence1[i]);
    }
    for(int i=0; i<n; i++){
        scanf("%d", &sequence2[i]);
    }

    static Stack s;
    s.top = -1;

    char ops[MAX][10];
    int opCount = 0;

    int i=0; //points seq1
    int j=0; //points seq2

    while(i<n){
        push(&s, sequence1[i]);
        strcpy(ops[opCount++], "Push");
        i++;

        while(!isEmpty(&s) && j<n && peek(&s) == sequence2[j]){
            pop(&s);
            strcpy(ops[opCount++], "Pop");
            j++;
        }
    }


    //check if all of seq2 was matched
    if(j==n){
        for(int k=0; k<opCount; k++){
            printf("%s\n", ops[k]);
        }
    } else {
        printf("Impossible\n");
    }

    return 0;

}