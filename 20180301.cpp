#include <iostream>
using namespace std;
int main()
{
    int t, sc = 0,cnt=0;
    do
    {
        cin >> t;
        if (t == 1){
            ++sc;
            cnt = 0;
        }
        else if (t == 2)
        {
            ++cnt;
            sc += cnt * 2;
        }
    } while (t);
    cout<< sc;
}