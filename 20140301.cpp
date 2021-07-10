#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[501]={0},b[1001]={0},cnt=0;
    for (int i = 0; i < n;++i){
        cin >> a[i];
        if(a[i]+b[abs(a[i])]==0)
            ++cnt;
        else if(b[abs(a[i])]==0)
            b[abs(a[i])] = a[i];
    }
    cout << cnt;
}