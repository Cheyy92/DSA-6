#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100

//Stack for integers
typedef struct{
    int data[MAX];
    int top;
}IntStack;

//Stack for strings;
typedef struct{
    char data[MAX][MAX];
    int top;
}StrStack;

void intPush(IntStack *s, int val){
    s->data[++(s->top)] = val;
}

int intPop(IntStack *s){
    return s->data[(s->top)--];
}

void strPush(StrStack *s, char *str){
    strcpy(s->data[++(s->top)], str);
}

char* strPop(StrStack *s){
    return s->data[(s->top)--];
}

int main(){
    int n;
    scanf("%d", &n);
    char encoded[MAX];
    scanf("%s", encoded);

    IntStack countStack;
    StrStack stringStack;
    countStack.top = -1;
    stringStack.top = -1;

    char curr[MAX] = "";
    int k=0;

    for(int i=0; i<n; i++){
        char c = encoded[i];

        if(isdigit(c)){
            k = k*10+(c-'0');
        }

        else if(c=='['){
            //Save state
            intPush(&countStack, k);
            strPush(&stringStack, curr);

            //reset for new context
            k = 0;
            curr[0] = '\0'; //current is reverted after pushing
        }

        else if(c == ']'){
            int repeat = intPop(&countStack);
            char *prev = strPop(&stringStack);

            //repeat the current string 'repeat' times, append to prev
            char temp[MAX];
            strcpy(temp, prev);
            for(int j=0; j<repeat; j++){
                strcat(temp, curr);
            }
            strcpy(curr, temp);
        } 

        else{
            //append to current if faced with char
            int len = strlen(curr);
            curr[len] = c;
            curr[len+1] = '\0';
        }
    }

    printf("%s\n", curr);
    return 0;



}