#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,t,id,pos;
    cin >> n >> t;
    vector<int> v;
    for (int i = 1; i <= n;++i){
        v.emplace_back(i);
    }
    for (int i = 0; i < t;++i){
        cin >> id >> pos;
        for (int j = 0; j < n;++j){
            if(v[j]==id){
                v.erase(v.begin() + j);
                v.emplace(v.begin() + j + pos,id);
                break;
            }
        }
    }
    for (int i = 0; i < n;++i){
        printf("%d ", v[i]);
    }
}