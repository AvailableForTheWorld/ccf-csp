#include<iostream>
using namespace std;
#define N 100
struct node{
    int val;
    node *next;
    node():next(nullptr){}
} nd[N];

int main(){
    int n,m;
    cin >> n>>m;
    for (int i = 0; i < n;++i){
        node *tail=&nd[i];
        for (int j = 0; j <m;++j){
            int t;
            cin >> t;
            node *p=new node;
            p->val = t;
            tail->next = p;
            tail = tail->next;
        }
    }
    for (int i = n - 1; i >= 0;--i){
        node *p = &nd[i];
        while(p->next){
            cout << p->next->val << " ";
            p = p->next;
        }
        cout << endl;
    }
}