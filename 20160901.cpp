#include<iostream>
using namespace std;
int main(){
    int n,a[1001],maxi=-1;
    cin >> n;
    for (int i = 0; i < n;++i){
        scanf("%d", &a[i]);
        if(i&&abs(a[i]-a[i-1])>maxi)
            maxi = abs(a[i] - a[i - 1]);
    }
    cout << maxi;
}