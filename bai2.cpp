#include <bits/stdc++.h>
#define ElementType int
using namespace std;

struct Node{
    ElementType Info;
    Node* pNext;
};

typedef struct{
    Node* pTop;
}STACK;

Node* CreateNode(ElementType x){
    Node* p = new Node;
    if(p == NULL) return NULL;
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void InitStack(STACK &s){
    s.pTop = NULL;
}

int IsEmptyStack(STACK s){  //1: stack rỗng, 0: stack k rỗng
    if(s.pTop == NULL)
        return 1;
    else
        return 0;
}

int Push(STACK &s, ElementType x){
    Node* p = CreateNode(x);
    if(p == NULL) return 0;
    p->pNext = s.pTop;
    s.pTop = p;
    return 1;
}

Node* Pop (STACK &s){
    if(IsEmptyStack(s) == 1)
        return NULL;
    Node* p = s.pTop;
   // x = s.pTop->Info;
    s.pTop = s.pTop->pNext;
   // delete p;
    return p;
}

Node* Top(STACK s){
    if(IsEmptyStack(s)) return NULL;
    return s.pTop;
}

int IsFullStack(STACK s){
    Node* p = new Node;
    if(p == NULL) return 1;
    delete p;
    return 0;
}

int main(){
    STACK s;
    InitStack(s);

    Push(s, 10);
    Push(s, 20);
    Push(s, 30);

    Node* topNode = Top(s);
    if (topNode != NULL) {
        cout << "Top: " << topNode->Info << endl;
    }

    Node* poppedNode = Pop(s);
    if (poppedNode != NULL) {
        cout << "Pop: " << poppedNode->Info << endl;
        delete poppedNode;  // Giải phóng bộ nhớ sau khi trích hủy
    }

    topNode = Top(s);
    if (topNode != NULL) {
        cout << "Next Top: " << topNode->Info << endl;
    }

    return 0;
}
