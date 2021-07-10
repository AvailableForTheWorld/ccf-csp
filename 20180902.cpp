#include <iostream>
using namespace std;
struct H
{
    int s, e;
} h[2001];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        
        scanf("%d%d", &h[i].s, &h[i].e);
    }
    long long t = 0;
    int c, d;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &c, &d);
        for (int j = 0; j < n; ++j)
        {
            if (c >= h[j].s && c < h[j].e)
            {
                if (d < h[j].e)
                {
                    t += d - c;
                    break;
                }
                else if (d > h[j].e)
                    t += (h[j].e - c);
            }
            else if (d > h[j].s && d <= h[j].e)
            {
                t += d - h[j].s;
                break;
            }
            else if (c <= h[j].s && d >= h[j].e)
            {
                t += h[j].e - h[j].s;
            }
        }
    }
    cout << t;
    return 0;
}