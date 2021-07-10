#include <iostream>
using namespace std;
int a[501][501];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int t, i, j;
    for (int k = 1; k < 2 * n; ++k)
    {
        if (k <= n)
        {
            i = k;
            j = 1;
            t = k;
        }
        else
        {
            i = n;
            j = k+1-n;
            t = 2 * n - k;
        }
        if(k%2==0)
            swap(i, j);
        for (int l = 1; l <= t; ++l)
        {
            if (k % 2)
                printf("%d ", a[i--][j++]);
            else
                printf("%d ", a[i++][j--]);
        }
    }
}