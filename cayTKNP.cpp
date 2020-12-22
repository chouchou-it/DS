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

int isEmpty(Tree T) {
    if(T != NULL) return 0;
    else return 1;
}

Tree initTree() {
    Tree T = NULL;
    return T;
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

int deleteMin(Tree *pT) {
    int k = 0;
    if((*pT)->Left == NULL) {
        k = (*pT)->Key;
        (*pT) = (*pT)->Right;
        return k;
    }
    else return deleteMin(&(*pT)->Left);
}

void deleteNode(int x, Tree *pT) {
    if((*pT) != NULL) {
        if(x < (*pT)->Key) deleteNode(x, &(*pT)->Left);
        else if(x > (*pT)->Key) deleteNode(x, &(*pT)->Right);
             else if(((*pT)->Left == NULL) && ((*pT)->Right == NULL))
                        (*pT) = NULL;
                  else if((*pT)->Right == NULL) (*pT) = (*pT)->Left;
                       else if((*pT)->Left == NULL) (*pT) = (*pT)->Right;
                            else (*pT)->Key = deleteMin(&(*pT)->Right);
    }
}

void printPath(int x, Tree T) {
    if(T != NULL) {
        if(x > T->Key) {
            printf("%d ", T->Key);
            printPath(x, T->Right);
        }
        if(x < T->Key ) {
            printf("%d ", T->Key);
            printPath(x, T->Left);
        }
        if(T->Key == x) {
            printf("%d -> Tim thay", T->Key);
        }
    }
    else printf("-> Khong thay");
}

int checkIn(int x, Tree T) {
    if(T != NULL) {
        if(T->Key == x) return 1;
        else 
            if(T->Key > x) return checkIn(x, T->Left);
            else 
                return checkIn(x, T->Right);
    }
    else return 0;
}

//Nut cha cua khoa x
Tree getParent(int x, Tree T) {
    if(!checkIn(x, T)) return NULL;
    else {
        if(T->Left->Key == x) return T;
        if(T->Right->Key == x) return T;
        if(T->Key > x) return getParent(x, T->Left);
        else return getParent(x, T->Right);
    }
}

//Con phai nhat
Tree maxRight(Tree T) {
    Tree p = T;
    while(p->Right != NULL) {
        p = p->Right;
    }
    return p;
}

//Cn trai nhat
Tree minLeft(Tree T) {
    Tree p = T;
    while(p->Left != NULL) {
        p = p->Left;
    }
    return p;
}

//Nut sau khoa x
Tree getNext(int x, Tree T) {
    if(T->Key == x) return minLeft(T->Right);
    else if(maxRight(T)->Key == x) return NULL;
    else if(x == maxRight(T->Left)->Key) return T;
    if(T->Key > x) return getNext(x, T->Left);
        else return getNext(x, T->Right);
}

//Nut dung truoc khoa x
Tree getPrevious(int x, Tree T) {
    if(x == T->Key) return minLeft(T);
    else if(x == minLeft(T->Right)->Key) return T;
    else if(x == minLeft(T->Left)->Key) return NULL;
    if(x > T->Key) return getPrevious(x, T->Right);
        else return getPrevious(x, T->Left);
}

int max(int a, int b){
    if (a > b) return a;
    return b;
}

/*

*/
int height(Tree T){
    if(T == NULL)
        return 0;
    else{
        return  1 + max(height(T->Left),height(T->Right));
    }
}

//Chieu cao tu nut goc den nut la xa nhat. Else tra ve -1
int getHeight(Tree T) {
    if(T == NULL) return -1;
    else return height(T)-1;
}

//Chieu cao tu goc den khoa x
int hNode(int x, Tree T) {  
    if(!checkIn(x, T)) return -1;
    else {
        Tree temp = searchNode(x, T);
        return getHeight(temp);
    }
}

