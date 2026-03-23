#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;


typedef struct Stack{
    Node *top;
    int min;
}Stack;


bool isEmpty(Stack *s){
    return s->top == NULL;
}

void peek(Stack *s){
    if(!isEmpty(s)){
        printf("Top: %d\n", s->top->value);
    }
    
}

void push(Stack *s, int x){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = x;
    newNode->next = NULL;
    if(!isEmpty(s)){
        newNode->next = s->top;
    }
    s->top = newNode;

}

void pop(Stack*s){
    if(!isEmpty(s)){
        Node *temp = s->top;
        s->top = s->top->next;
        int popped = temp->value;
        free(temp);

        printf("Popped: %d\n", popped);

        if(s->min == popped){
            int min = 10000;
            Node *curr = s->top;
            
            while(curr!=NULL){
                if(curr->value < min){
                    min = curr->value;
                    s->min = min;
                }
                curr = curr->next;
            }
              
        }
    }
    
    
}

int main(){
    int n;
    scanf("%d", &n);
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    int min = 100000;
    s->min = min;

    for(int i=0; i<n; i++){
        int op;
        scanf("%d", &op);

        if(op == 1){
            int x;
            scanf("%d", &x);
            push(s, x);
            if(x < s->min){
                s->min = x;
            }
        }

        if(op == 2){
            pop(s);
        }

        if(op==3){
            if(!isEmpty(s)){
                printf("Minimum: %d\n", s->min);
            } else {
                printf("Stack Empty\n");
            }
            
        }

        if(op==4){
            peek(s);
        }
    }
}