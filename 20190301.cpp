#include <iostream>
#include <cmath>
using namespace std;
int a[100001];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    if (a[0] < a[n - 1])
    {
        int tmp = a[0];
        a[0] = a[n - 1];
        a[n - 1] = tmp;
    }
    printf("%d ", a[0]);
    if (n % 2)
        printf("%d ", a[n / 2]);
    else{
        if((a[n/2]+a[n/2-1])%2)
            printf("%.1lf ", (a[n/2]+a[(n-1)/2])*1.0/2);
        else
            printf("%d ", (a[n / 2] + a[(n - 1) / 2]) / 2);
    }  
    printf("%d", a[n - 1]);
    return 0;
}