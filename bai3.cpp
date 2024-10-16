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

void Chuyendoicoso(int decimal){
    STACK s;
    InitStack(s);
    while (decimal > 0){
        int tmp = decimal % 2;
        Push(s, tmp);
        decimal = decimal / 2;
    }

    cout << "Gia tri nhi phan: ";
    while(!IsEmptyStack(s)){
        Node* p = Pop(s);
        cout << p->Info; // In ra giá trị nhị phân
        delete p; // Giải phóng bộ nhớ
    }
    cout << endl;
}

void Nhapmang(int a[], int n){
    cout << "Nhap so luong phan tu: ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}
void Daomang(int a[], int n){
    STACK s;
    InitStack(s);

    for(int i = 0; i < n; i++){
        Push(s, a[i]);
    }
    for(int i = 0; i < n; i++){
        Node* p = Pop(s);
        a[i] = p->Info;
        delete p;
    }
}

void Daochuoi(string chuoi){
    STACK s;
    InitStack(s);
    for(int i = 0; i < chuoi.length(); i++){
        Push(s, chuoi[i]);
    }

    string daostr;
    while (!IsEmptyStack(s))
    {
        Node* p = Pop(s);
        daostr += p->Info;
        delete p;
    }
}

void Xuatmang(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}


// Hàm kiểm tra tính đúng đắn của dấu ngoặc
bool BracketMatching(string expression) {
    STACK s;
    InitStack(s);

    for (char ch : expression) {
        // Nếu là dấu ngoặc mở, đẩy vào ngăn xếp
        if (ch == '(' || ch == '{' || ch == '[') {
            Push(s, ch);
        }
        // Nếu là dấu ngoặc đóng, kiểm tra
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (IsEmptyStack(s)) {
                return false; // Dấu ngoặc đóng không có dấu ngoặc mở tương ứng
            }
            Node* p = Pop(s);
            char topChar = p->Info;
            delete p; // Giải phóng bộ nhớ

            // Kiểm tra xem dấu ngoặc đóng có khớp với dấu ngoặc mở không
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    // Kiểm tra xem ngăn xếp còn dấu ngoặc mở nào không
    return IsEmptyStack(s);
}


int main(){
    int a[100], n;
    int decimal;
    cout << "Nhap so nguyen duong de chuyen sang nhi phan: ";
    cin >> decimal;
    Chuyendoicoso(decimal);

    Nhapmang(a,n);
    //int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Mảng ban đầu: ";
    Xuatmang(a,n);
    Daomang(a, n);
    cout << "Mang sau khi dao nguoc: ";
    Xuatmang(a,n);

    string input;
    cout << "Nhap chuoi: ";
    cin.ignore();
    getline(cin, input);
    cout << "Chuoi sau khi dao: "<< Daochuoi << endl;

    string expression;
    cout << "Nhap bieu thuc (dung ngoac): ";
    getline(cin, expression);
    
    if (BracketMatching(expression)) {
        cout << "Dau ngoac hop le!" << endl;
    } else {
        cout << "Dau ngoac khong hop le!" << endl;
    }

    return 0;
}

