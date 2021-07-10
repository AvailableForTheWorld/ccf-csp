#include<iostream>
using namespace std;
int main(){
    long long time = 0;
    int r, y, g;
    cin >> r >> y >> g;
    int n;
    cin >> n;
    for (int i = 0; i < n;++i){
        int id, span;
        scanf("%d%d", &id, &span);
        if(id==0)
            time += span;
        else if(id==3)
            continue;
        else if(id==1){
            time += span;
        }else if(id==2)
            time += (span + r);
    }
    cout << time;
}