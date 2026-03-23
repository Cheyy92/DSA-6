#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    char chr;
    struct Node* next;
}Node;

typedef struct Stack{
    Node* top;
    int size;
}Stack;

bool isEmpty(Stack *s){
    return s->top == NULL;
}

void push(Stack *s, char c){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->chr = c;
    newNode->next = NULL;
    if(!isEmpty(s)){
        newNode->next = s->top;
    }
    s->top = newNode;
    s->size++;
}

char pop(Stack*s){
    if(!isEmpty(s)){
        char popped = s->top->chr;
        Node *temp = s->top;
        s->top = temp->next;
        free(temp);
        s->size--;
    }
}

int main(){
    char str[100];
    scanf("%s", str);

    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;

    int validCount = 0;
    
    for(int i=0; str[i]!='\0'; i++){
        if(str[i]=='('){
            push(s, str[i]);
        } 
        else if(!isEmpty(s) && str[i]==')') {
            char c = pop(s);
            validCount++;
        }
    }

    printf("%d", validCount*2);
}