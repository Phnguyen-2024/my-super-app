#include <bits/stdc++.h>
#define MAXSIZE 100
#define ElementType int
using namespace std;

struct STACK{
    int a[MAXSIZE];
    int t;
};

void InitSatck(STACK& s){
    s.t = -1;
}

int IsEmptyStack(STACK s){
    if(s.t == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int IsFullStack(STACK s){
    if(s.t >= MAXSIZE - 1){
        return 1;
    }
    else{
        return 0;
    }
}

void Push (STACK &s, int x){
    if (IsFullStack(s) == 0){
        s.t++;
        s.a[s.t] = x;
    }
    else{
        cout << "Khong the them vao STACK\n";
    }
}

ElementType Pop(STACK &s, int &x){
    if(IsEmptyStack(s) == 0){
        x = s.a[s.t];
        s.t--;
        return 1;
    }
    else{
        cout << "Ngan xep rong" << endl;
        return 0;
    }
}

ElementType Top(STACK s){
    return s.a[s.t];
}


int main(){
    STACK s;
    InitSatck(s);

    Push(s, 10);
    Push(s, 20);
    Push(s, 30);

    cout << "Top: " << Top(s) << endl;

    int poppedValue;
    Pop(s, poppedValue);
    cout << "Pop: " << poppedValue << endl;

    cout << "Next top: " << Top(s) << endl;

    return 0;
}