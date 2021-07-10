#include<iostream>
using namespace std;
int a[1001];
int main(){
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n;++i){
        scanf("%d", &a[i]);
        if(i>1){
            if((a[i]-a[i-1])*(a[i-1]-a[i-2])<0)
                ++cnt;
        }
    }
    cout << cnt;
    return 0;
}