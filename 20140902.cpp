#include<iostream>
using namespace std;
int a[101][101]={0};
int main(){
    int n,x1,y1,x2,y2;
    cin >> n;
    for (int i = 0; i < n; ++i){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (int j = x1; j < x2; ++j){
            for (int k = y1; k < y2; ++k){
                a[j][k] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 101; ++i){
        for (int j = 0; j < 101; ++j){
            if(a[i][j])
                ++cnt;
        }
    }
    cout << cnt;
}