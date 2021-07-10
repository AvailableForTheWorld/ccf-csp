#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int flag, n, len = s.length();
    cin >> flag >> n;
    for (int i = 0; i < n; ++i)
    {
        string s1;
        cin >> s1;
        int len1 = s1.length();
        if (!flag)
        {
            int j, k;
            j = k = 0;
            while (j < len1 && k < len)
            {
                if (tolower(s1[j]) == tolower(s[k]))
                {
                    ++j;
                    ++k;
                }
                else
                {
                    j -= (k - 1);
                    k = 0;
                }
            }
            if (k == len)
            {
                cout << s1 << endl;
            }
        }
        else if (s1.find(s) != string::npos)
            cout << s1 << endl;
    }
    return 0;
}