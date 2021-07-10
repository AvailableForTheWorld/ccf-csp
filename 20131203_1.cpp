#include<iostream>
using namespace std;
int a[1001];
long long dp[1001][1001];
int main(){
    int n;
    long long res=-1;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        scanf("%d",&a[i]);	
        for (int j = 1; j <= a[i]; ++j){
            dp[i][j] = a[i-1]>=j? dp[i-1][j]+j : j;
            if(dp[i][j]>res)
                res = dp[i][j];
        }
    }
    cout << res;
}