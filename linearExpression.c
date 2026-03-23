#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct Node{
    float value;
    struct Node* next;
}Node;

typedef struct Stack{
    Node *top;
    int size;
}Stack;

bool isEmpty(Stack *s){
    return s->top == NULL;
}

void push(Stack *s, float x){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = x;
    newNode->next = NULL;
    if(!isEmpty(s)){
        newNode->next = s->top;
    }
    s->top = newNode;
    s->size++;
}

float pop(Stack *s){
    if(!isEmpty(s)){
        float popped = s->top->value;
        Node *temp = s->top;
        s->top = s->top->next;
        s->size--;
        free(temp);
        return popped;
    }
}

float peek(Stack *s){
    return s->top->value;
}

int size(Stack *s){
    return s->size;
}

int main(){
    char str[100];
    scanf("%s", str);

    //Initialize stack
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;

    for(int i=0; str[i]!= '\0'; i++){
        if(isdigit(str[i])){
            float digit = (float)(str[i]-'0');
            push(s, digit);
        }

        if(str[i]=='*'){
            float right = 0;
            float left = 0;
            if(!isEmpty(s)){
                right = pop(s);
                if(!isEmpty(s)){
                    left = pop(s);
                } else {
                    printf("Invalid Expression");
                    return -1;
                }
            } else {
                printf("Invalid Expression");
                return -1;
            }

            float result = left*right;
            push(s, result);    
        }
        if(str[i]=='+'){
            float right = 0;
            float left = 0;
            if(!isEmpty(s)){
                right = pop(s);
                if(!isEmpty(s)){
                    left = pop(s);
                } else {
                    printf("Invalid Expression");
                    return -1;
                }
            } else {
                printf("Invalid Expression");
                return -1;
            }

            float result = left + right;
            push(s, result);
        }
        if(str[i] == '-'){
            float right = 0;
            float left = 0;
            if(!isEmpty(s)){
                right = pop(s);
                if(!isEmpty(s)){
                    left = pop(s);
                } else {
                    printf("Invalid Expression");
                    return -1;
                }
            } else {
                printf("Invalid Expression");
                return -1;
            }

            float result = left - right;
            push(s, result);
        }
        if(str[i] == '/'){
            float right = 0;
            float left = 0;
            if(!isEmpty(s)){
                right = pop(s);
                if(!isEmpty(s)){
                    left = pop(s);
                } else {
                    printf("Invalid Expression");
                    return -1;
                }
            } else {
                printf("Invalid Expression");
                return -1;
            }

            if(right == 0){
                printf("Invalid Expression");
                return -1;
            }

            float result = left/right;
            push(s, result);
        }
    }

    if(s->size!=1){
        printf("Invalid Expression");
        return -1;
    } else {
        float result = pop(s);
        printf("%.2f", result);
        return 0;
    }
}

