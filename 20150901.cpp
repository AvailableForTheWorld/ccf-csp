#include <iostream>
using namespace std;
int main()
{
    int n, a[1001] = {0}, cnt = 1;
    cin >> n;
    for (int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        if(i&&a[i]!=a[i-1])
            ++cnt;
    }
    cout << cnt;
    return 0;
}