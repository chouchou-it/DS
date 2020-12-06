#include<stdio.h>

typedef int ElementType;
typedef int Position;
typedef struct {
    ElementType Elements[100];
    int Last;
} List;

void makenullList(List *pL) {
    pL->Last = 0;
}

Position endList(List L) {
    return L.Last;
}

Position firstList(List L) {
    return 1;
}

void insertSet(ElementType x, List *pL) {
    pL->Elements[pL->Last] = x;
    pL->Last++;
}

Position member(ElementType x, List L) {
    int check = 0;
    for(int i = 0 ; i < L.Last ; i++) {
        if(L.Elements[i] == x) 
            check = 1;
    }
    if(check == 1) return 1;
    else return 0;
}

Position locate(int x, List L) {
    int found = 0;
    int i     = 0;
    while(i <= L.Last && found == 0) {
        if(L.Elements[i] == x)
            found = 1;
        i++;
    }
    if(found == 1) return i;
    else return L.Last+1;
}

void deleteList(int p, List *pL) {
    if(p < 1 || p > pL->Last) 
        printf("Vi tri nhap khong hop le\n");
    for(int i = p ; i <= pL->Last ; i++) {
        pL->Elements[i-1] = pL->Elements[i];
    }
    pL->Last--;
}

void readList(List *pL) {
    makenullList(pL);
    int n;
    ElementType x;
    for(int i = 0 ; i < n ; i++) {
        scanf("%d", &x);
        insertSet(pL->Elements[i], pL);
    }
}

void printList(List L) {
    for(int i = 0 ; i < L.Last ; i++) {
        printf("%d ", L.Elements[i]);
    }
    printf("\n");
}

void insertList(ElementType x, int p, List *pL) {
    if(p < 0 || p > pL->Last) 
        printf("Vi tri khong hop le\n");
    else {
        for(int i = pL->Last ; i >= p ; i--) {
            pL->Elements[i] = pL->Elements[i-1];
        }
        pL->Elements[p-1] = x;
        pL->Last++;
    }
}

void printOddnumber(List L) {
    for(int i = 0 ; i < L.Last ; i++) {
        if(L.Elements[i]%2 != 0) {
            printf("%d ", L.Elements[i]);
        }
    }
}

//hop 2 tap hop
void unionSet(List L1, List L2, List *pL) {
    makenullList(pL);
    for(int i = 0 ; i < L1.Last ; i++) {
        insertSet(L1.Elements[i], pL);
    }
    for(int i = 0 ; i < L2.Last ; i++) {
        if(!member(L2.Elements[i], *pL)) 
            insertSet(L2.Elements[i], pL);
    }
}

//giao 2 tap hop
void intersection(List L1, List L2, List *pL) {
    makenullList(pL);
    for(int i = 0 ; i < L1.Last ; i++) {
        if(member(L1.Elements[i], L2)) 
            insertSet(L1.Elements[i], pL);
    }
}

//hieu 2 tap hop
void differnce(List L1, List L2, List *pL) {
    makenullList(pL);
    for(int i = 0 ; i < L1.Last ; i++) {
        if(member(L1.Elements[i], L2)) 
            insertSet(L1.Elements[i], pL);
    }
}

float getAVG(List L) {
    float sum = 0;
    int count = 0;
    if(L.Last == 0) return -10000.00;
    for(int i = 0 ; i < L.Last ; i++) {
        sum += L.Elements[i];
        count++;
    }
    return sum/count;
}

void normalize(List *pL) {
    Position P = 0, Q;
    while(P != pL->Last + 1) {
        Q = P + 1;
        while (Q != pL->Last + 1) {
            if(pL->Elements[P-1] == pL->Elements[Q-1])
                deleteList(P, pL);
            Q++;
        }
        P++;
    }
}

void erase(ElementType x, List *pL) {
    int p = locate(x, *pL);
    deleteList(p, pL);
}

void removeAll(int x, List *pL) {
    int p = locate(x, *pL);
    while (p <= pL->Last || p > 0) {
        deleteList(p, pL);
        p = locate(x, *pL);
    }
}

void sapxepList(List *pL) {
    for(int i = 0 ; i < pL->Last ; i++) {
        for(int j = i + 1 ; j < pL->Last+1 ; j++) {
            if(pL->Elements[i] > pL->Elements[j]) {
                ElementType temp;
                temp            = pL->Elements[i];
                pL->Elements[i] = pL->Elements[j];
                pL->Elements[j] = temp;
            }
        }
    }
}

