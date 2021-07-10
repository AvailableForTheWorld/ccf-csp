#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> P;
int cmp(P a,P b){
    if(a.second==b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main(){
    vector<P> v;
    map<int, int> m;
    int n,t;
    cin >> n;
    for (int i = 0; i < n;++i){
        scanf("%d", &t);
        ++m[t];
    }
    for(auto it=m.begin();it!=m.end();++it){
        v.emplace_back(P(it->first, it->second));
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[0].first ;
    return 0;
}