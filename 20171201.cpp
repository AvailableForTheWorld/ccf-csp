#include<iostream>
#include<queue>
using namespace std;
int main(){
    int n,t;
    cin >> n;
    priority_queue<int> pque;
    for (int i = 0; i < n;++i){
        scanf("%d", &t);
        pque.emplace(t);
    }
    int mini = INT_MAX;
    while(!pque.empty()){
        t = pque.top();
        pque.pop();
        if(pque.empty())
            break;
        if(mini>t-pque.top())
            mini = t-pque.top();
    }
    cout << mini;
}