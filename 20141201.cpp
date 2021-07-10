#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int main(){
    int n,t;
    cin >> n;
    int a[1001];
    memset(a, 0, sizeof(a));
    vector<int> v;
    for (int i = 0; i < n; ++i){
        scanf("%d", &t);
        ++a[t];
        v.emplace_back(a[t]);
    }
    for(auto i:v)
        printf("%d ", i);
}