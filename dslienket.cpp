#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct Node{
    ElementType Element;
    Node *Next;
};
typedef Node *Position;
typedef Position List;

void makenullList(List *pL) {
    (*pL)->Next = NULL;
}


//kiem tra x co ton tai trong List khong ?
int member(ElementType x, List L) {
    List p = L;
    int check = 0;
    while(p->Next != NULL && check == 0) {
        if(p->Next->Element == x) 
            check = 1;
        else p = p->Next;
    }
    return check;
}

//tra ve vi tri dau tien cua x
Position locate(ElementType x, List L) {
    Position p = L;
    int found = 0;
    while (p->Next != NULL && found == 0 ) {
        if(p->Next->Element == x)
            found = 1;
        else p = p->Next;
    }
    return p;
}

void deleteList(Position p, List *pL) {
    Position t;
    if(p->Next != NULL) {
        t = p->Next;
        p->Next = p->Next->Next;
        free(t);
    }
}

//noi x vao List 
void append(ElementType x, List *pL) {
    Position p = (*pL);
    while(p->Next != NULL) 
        p = p->Next;
    Position t;
    t = (Node*)malloc(sizeof(Node));
    t->Element = x;
    t->Next    = NULL;
    p->Next    = t;
}

void addFirst(ElementType x, List *pL) {
    Position p;
    p = (Node*)malloc(sizeof(Node));
    p->Element   = x;
    Position q   = *pL;
    p->Next      = q->Next;
    q->Next      = p;           
}

List readSet() {
    List L;
    makenullList(&L);
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        ElementType x;
        scanf("%d", &x);
        if(!member(x, L)) 
            addFirst(x, &L);
    }
    return L;
}

void erase(ElementType x, List *pL) {
    Position p = locate(x, *pL);
    if(p->Next != NULL)
        deleteList(p, pL);
    else printf("Not found %d\n", x);
}

//chuan hoa danh sach
void normalize(List *pL) {
    Position p = *pL;
    while (p->Next != NULL) {
        Position q = p->Next;
        while (q->Next != NULL) {
            if(p->Next->Element == q->Next->Element)
                deleteList(q, pL);
            else q = q->Next;
        }
        p = p->Next;
    }
}

void insertList(ElementType x, Position p, List *pL) {
    Position t;
    t = (Node*)malloc(sizeof(Node));
    t->Element  = x;
    t->Next     = p->Next;
    p->Next     = t;
}

void sort(List *pL) {
    Position p = *pL;
    while(p->Next != NULL) {
        Position q = p->Next;
        while (q->Next != NULL) {
            if(p->Next->Element > q->Next->Element) {
                ElementType temp;
                temp             = p->Next->Element;
                p->Next->Element = q->Next->Element;
                q->Next->Element = temp;
            }
            q = q->Next;
        }
        p = p->Next;
    }
}

//hop 2 tap hop
List unionSet(List L1, List L2) {
    List pL;
    makenullList(&pL);
    pL = L1;
    Position q = L2;
    while (q->Next != NULL) {
        if(!member(q->Next->Element, pL))
            append(q->Next->Element, &pL);
        q = q->Next;
    }
    return pL;
}

