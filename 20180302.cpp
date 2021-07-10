#include <iostream>
#include<algorithm>
using namespace std;
int a[101],b[101];
struct Q{
    int val, id;
} q[101];
int cmp(Q a,Q b){
    return a.val < b.val;
}
int main()
{
    int n, len, t;
    cin >> n >> len >> t;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        q[i].val = a[i];
        q[i].id = i;
        a[i] = (a[i] + t) % (2 * len) > len ? 2 * len - (a[i] + t) : (a[i] + t) % len;
    }
    sort(q, q + n, cmp);
    sort(a, a + n);
    for (int i = 0; i < n;++i){
        b[q[i].id] = a[i];
    }
    for (int i = 0; i < n;++i){
        printf("%d ", b[i]);
    }
}
