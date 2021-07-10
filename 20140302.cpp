#include<iostream>
using namespace std;
struct panel{
    int x1, y1, x2, y2, id;
} P[11];
void swap(panel &c,panel &d){
    int x1 = d.x1, y1 = d.y1, x2 = d.x2, y2 = d.y2,id=d.id;
    d = {c.x1, c.y1, c.x2, c.y2,c.id};
    c = {x1, y1, x2, y2, id};
}
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;++i){
        scanf("%d%d%d%d", &P[i].x1, &P[i].y1, &P[i].x2, &P[i].y2);
        P[i].id = i;
    }
    int a, b;
    while(m--){
        int flag = 1;
        scanf("%d%d", &a, &b);
        for (int i = n; i >= 1;--i){
            if(a>=P[i].x1&&a<=P[i].x2&&b>=P[i].y1&&b<=P[i].y2)
            {
                printf("%d\n", P[i].id);
                swap(P[i], P[n]);
                flag = 0;
                break;
            }
        }
        if(flag)
            cout << "IGNORED" << endl;
    }
    return 0;
}