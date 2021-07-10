#include<iostream>
using namespace std;
int a[1001],b[1001];
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n;++i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n;++i){
        if(i==0){
            b[i] = (a[i] + a[i + 1]) / 2;
        }else if(i==n-1){
            b[i] = (a[i] + a[i - 1]) / 2;
        }else{
            b[i] = (a[i] + a[i - 1] + a[i + 1]) / 3;
        }
        printf("%d ", b[i]);
    }
    return 0;
}