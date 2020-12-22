#include<stdio.h>
#include<stdlib.h>

typedef int KeyType;
struct Node {
    KeyType Key;
    struct Node *Left;
    struct Node *Right;
};
typedef struct Node *Tree;

void posOrder(Tree T) {
    if(T != NULL ) {
        posOrder(T->Left);
        posOrder(T->Right);
        printf("%d ", T->Key);
    }
}

void inOrder(Tree T) {
    if(T != NULL) {
        inOrder(T->Left);
        printf("%d ", T->Key);
        inOrder(T->Right);
    }
}

void preOrder(Tree T) {
    printf("%d ", T->Key);
    preOrder(T->Left);
    preOrder(T->Right);
}

Tree searchNode(int x, Tree T) {
    if(T == NULL) return NULL;
        else if(T->Key == x) return T;
            else if(x > T->Key) return searchNode(x, T->Right);
                    else return searchNode(x, T->Left);
}

void insertNode(int x, Tree *pT) {
    if((*pT) == NULL) {
        (*pT) = (struct Node*)malloc(sizeof(struct Node));
        (*pT)->Key  = x;
        (*pT)->Left = NULL;
        (*pT)->Right = NULL;
    }
    else if(x > (*pT)->Key) return insertNode(x, &(*pT)->Right);
         else if(x == (*pT)->Key);
              else return insertNode(x, &(*pT)->Left);
}

