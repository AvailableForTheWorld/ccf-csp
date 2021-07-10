#include<iostream>
using namespace std;
int a[1000];
int main(){
    int n, k,cnt=0,cur=0;
    cin >> n >> k;
    for (int i = 0; i < n;++i){
        scanf("%d", &a[i]);
        cur += a[i];
        if(cur>=k)
        {
            ++cnt;
            cur = 0;
        }
    }
    if(cur)
        ++cnt;
    cout << cnt;
}