#include<stdio.h>
int main(){	
    int n,i,j,h,r,l;	
    int res,x;	
    int a[1010];
    scanf("%d", &n);
    res = 0;
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (i = 1; i <= n; i++)
    {
        r = i + 1;
        l = i - 1;
        x = 1;
        while (r <= n && a[r] >= a[i])
        {
            x++;
            r++;
        }
        while (l >= 1 && a[l] >= a[i])
        {
            x++;
            l--;
        }
        x = x * a[i];
        res = x>res?x:res;	
    }	
    printf("%d\n",res);	
    return 0;
}