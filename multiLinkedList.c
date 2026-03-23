#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NeighbourNode{
    struct NeighbourNode* right;
    int value;
}NeighbourNode;

typedef struct BackboneNode{
    struct NeighbourNode* neighbours; //head of horizontal list
    struct BackboneNode* down; //next vertex in backbone
    int value;
}BackboneNode;

void addNeighbour(BackboneNode *node, int neighbour){
    NeighbourNode *newNode = (NeighbourNode*)malloc(sizeof(NeighbourNode));
    newNode->right = NULL;
    newNode->value = neighbour;

    if(node->neighbours == NULL){
        node->neighbours = newNode;
    } else {
        NeighbourNode *curr = node->neighbours;
        while(curr->right!=NULL){
            curr = curr->right;
        }
        curr->right = newNode;
    }
}



int main(){
    int n;
    scanf("%d", &n);
    int **matrix = (int**)malloc(n * sizeof(int*));
    for(int i=0; i<n; i++){
        matrix[i] = (int*)malloc(n*sizeof(int));
        for(int j=0; j<n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    BackboneNode *head = NULL;
    BackboneNode *tail = NULL;

    //Build backbone
    for(int i=0; i<n; i++){
        BackboneNode *node = (BackboneNode*)malloc(sizeof(BackboneNode));
        node->value = i;
        node->down = NULL;
        node->neighbours = NULL;
        if(head == NULL){
            head = node;
            tail = node;
        } else {
            tail->down = node;
            tail = node;
        }
    }

    //fill horizontal neighbours from adjacency matrix
    BackboneNode *curr = head;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j]==1){
                addNeighbour(curr, j);
            }
        }
        curr = curr->down;
    }

    //print the list;
    curr = head;
    for(int i=0; i<n; i++){
        printf("%d", curr->value);
        NeighbourNode *currNeighbour = curr->neighbours;
        while(currNeighbour!=NULL){
            printf(" -> %d", currNeighbour->value);
            currNeighbour = currNeighbour->right;
        }
        printf("\n");

        if(curr->down !=NULL) printf("|\n");
        curr = curr->down;
    }

    return 0;


}