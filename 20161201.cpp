#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,cnt=0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n;++i){
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    int i, j;
    for (i = (n - 1) / 2; i >= 0;--i){
        if(v[i]!=v[(n-1)/2]){
            break;
        }
    }
    for (j = (n - 1) / 2; j < n;++j){
        if(v[j]!=v[(n-1)/2]){
            break;
        }
    }
    if(i==n-j-1)
        cout << v[(n - 1) / 2];
    else
        cout << -1;
    return 0;
}