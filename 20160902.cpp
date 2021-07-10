#include<iostream>
using namespace std;
int main(){
    int n, a[101]={0},b[100],c[21]={0};
    cin >> n;
    for (int i = 0; i < n;++i){
        scanf("%d", &b[i]);
        int j;
        for (j = 1; j <21;++j){
            if(b[i]+c[j]<=5){
                for (int k = 1; k <= b[i];++k){
                    a[(j - 1) * 5 + c[j] + k] = 1;
                    printf("%d ", (j - 1) * 5 + c[j] + k);
                }
                c[j] += b[i];
                break;
            }
        }
        if(j==21){
            int t = b[i];
            for (int k = 1; k < 101;++k){
                if(!a[k]){
                    --t;
                    a[k] = 1;
                    printf("%d ", k);
                    if(!t){
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}