#include<iostream>
using namespace std;
int m, n, q;
char a[101][101];
void fill(int x,int y,char c){
    if(x<m&&x>=0&&y<n&&y>=0&&a[n-1-y][x]!='+'&&a[n-1-y][x]!='-'&&a[n-1-y][x]!='|'&&a[n-1-y][x]!=c)
    {
        a[n-1-y][x] = c;
        fill(x - 1, y, c);
        fill(x, y - 1, c);
        fill(x + 1, y, c);
        fill(x, y + 1, c);
    }
}
int main(){
    cin >> m >> n>>q;
    for (int i = 0; i < n;++i){
        for (int j = 0; j < m;++j){
            a[i][j]='.';
        }
    }
    int type, x1, y1, x2, y2, x, y;
    char c;
    for (int i; i < q; ++i){
        scanf("%d", &type);
        if(type){
            scanf("%d %d %c", &x, &y,&c);
            fill(x, y, c);
        }
        else {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            int flag = 0;
            if(x1>x2){
                int tmp = x1;
                x1 = x2;
                x2 = tmp;
                flag = 0;
            }else if(x1<x2)
                flag = 0;
            else if(y1>y2){
                flag = 1;
                int tmp = y1;
                y1 = y2;
                y2 = tmp;
            }
            else if(y1<y2){
                flag = 1;
            }
            if(!flag){
                for (int i = x1; i <= x2;++i){
                    if(a[n-1-y1][i]!='|'&&a[n-1-y1][i]!='+')
                        a[n - 1 - y1][i] = '-';
                    else if(a[n-1-y1][i]=='|')
                        a[n - 1 - y1][i] = '+';
                }
            }else if(flag){
                for (int i = y1; i <= y2;++i){
                    if(a[n-1-i][x1]!='-'&&a[n-1-i][x1]!='+')
                        a[n - 1 - i][x1] = '|';
                    else if(a[n-1-i][x1]=='-')
                        a[n - 1 - i][x1] = '+';
                }
            }
        }
    }
    for (int i = 0; i < n;++i){
        for (int j = 0; j < m;++j){
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
}