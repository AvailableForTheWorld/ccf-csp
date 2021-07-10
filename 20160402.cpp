#include<iostream>
using namespace std;
int a[16][11],b[5][5];
int main(){
    for (int i = 0; i < 15;++i){
        for (int j = 0; j < 10;++j){
            scanf("%d", &a[i][j]);
        }
    }
    int max_row = 0;
    for (int i = 0; i < 4;++i){
        for (int j = 0; j < 4;++j){
            scanf("%d", &b[i][j]);
            if(b[i][j]&&max_row<i)
                max_row = i;
        }
    }
    int col,flag,i,j,k,cur=0;
    cin >> col;
    for (k = 3; k <15;++k){
        flag = 1;
        for (i = 0; i <=max_row ; ++i)
        {
            for (j = 0; j < 4; ++j)
            {
                if (b[i][j] && a[k+i-max_row][j + col - 1])
                {
                    flag = 0;
                    break;
                }
            }
            if(!flag)
                break;
        }
        if(flag){
            cur = k;
        }
    }
    for (int i = 0; i <=max_row;++i){
                for (int j = 0; j < 4;++j){
                    if(b[i][j]){
                        a[cur + i - max_row][j + col - 1] = 1;
                    }
                }
            }
    for (int i = 0; i < 15;++i){
        for (int j = 0; j < 10;++j){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}