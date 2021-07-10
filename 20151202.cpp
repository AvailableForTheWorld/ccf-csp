#include <iostream>
using namespace std;
int main()
{
    int n, m, a[31][31], flag[31][31] = {0};
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int cnt, start;
    for (int i = 1; i <= n; ++i)
    {
        cnt = start = 0;
        for (int j = 1; j < m; ++j)
        {
            if (a[i][j] == a[i][j + 1])
            {
                ++cnt;
                if (!start)
                    start = j;
            }
            else if(cnt>=2){
                 for (int j = start; j < start + cnt+1; ++j)
                {
                    flag[i][j] = 1;
                }
                start= cnt = 0;
            }
            else if(cnt<2)
                start=cnt = 0;
        }
        if(cnt>=2)
            for (int j = start; j < start + cnt+1; ++j)
                {
                    flag[i][j] = 1;
                }
    }
    for (int j = 1; j <= m; ++j)
    {
        cnt = start = 0;
        for (int i = 1; i < n; ++i)
        {
            if (a[i][j] == a[i + 1][j])
            {
                ++cnt;
                if (!start)
                    start = i;
            }
            else if (cnt >= 2)
            {
                for (int i = start; i < start + cnt+1; ++i)
                {
                    flag[i][j] = 1;
                }
            }
            else if(cnt<2)
                start=cnt = 0;
        }
        if(cnt>=2)
            for (int i = start; i < start + cnt+1; ++i)
                {
                    flag[i][j] = 1;
                }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (flag[i][j])
            {
                printf("0 ");
            }
            else
                printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}