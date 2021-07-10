#include <iostream>
#include <algorithm>
using namespace std;
#define N 2010
struct Q
{
    int no, t, flag;
} q[N];
int box[N];
bool cmp(Q a, Q b)
{
    if (a.t != b.t)
        return a.t < b.t;
    else if (a.flag != b.flag)
        return a.flag > b.flag;
    else
        return a.no < b.no;
}
int main()
{
    int n, k, i, j, z = 0;
    int w, s, c;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        box[i] = i + 1;
    }
    for (int i = 0; i < k; ++i)
    {
        scanf("%d%d%d", &w, &s, &c);
        q[z].no = w;
        q[z].t = s;
        q[z].flag = -1;
        ++z;
        q[z].no = w;
        q[z].t = s + c;
        q[z].flag = 1;
        ++z;
    }
    sort(q, q + z, cmp);
    for (int i = 0; i < z; ++i)
    {
        if (q[i].flag == -1)
        {
            for (int j = 0; j < n; ++j)
            {
                if (box[j] == q[i].no)
                {
                    box[j] = 0;
                    break;
                }
            }
        }
        else
        {
            for (int j = 0; j < n; ++j)
            {
                if (!box[j])
                {
                    box[j] = q[i].no;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", box[i]);
    }
    return 0;
}