#include<iostream>
using namespace std;
int a[1001][1001];
int main(){
    int n,m;
    cin >> n >> m;
    long long T=0,max_sub=0,max_id=-1;
    for (int i = 1; i <= n;++i){
        long long sum ,sub=0;
        cin >> sum;
        for (int j = 1; j <= m;++j){
            scanf("%d", &a[i][j]);
            sub += a[i][j];
        }
        if(sub<max_sub){
            max_sub = sub;
            max_id = i;
        }
        sum += sub;
        T += sum;
    }
    printf("%lld %lld %lld", T, max_id, -max_sub);
}