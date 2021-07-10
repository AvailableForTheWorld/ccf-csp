#include<iostream>
using namespace std;
int trans[3] = {30, 30, 3};
int main(){
    int r, y, g;
    cin >> r >> y >> g;
    int n,id,span;
    long long time = 0,sum=0;
    cin >> n;
    for (int i = 0; i < n;++i){
        scanf("%d%d", &id, &span);
        
        if(id==0)
            time += span;
        else {
            int flag = id,stop=0;
            while(span-time<0){
                span += trans[flag];
                sum += trans[flag];
                if(flag)
                flag = (flag + 1) % 3;
            }
            
        }
    }
}