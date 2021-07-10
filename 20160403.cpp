#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s, s1 = "";
    cin >> s;
    int len1 = s.size();
    vector<string> org;
    for (int i = 0; i < len1; ++i)
    {
        if (s[i] == '/')
        {
            if (s1 != "." && s1 != "")
                org.emplace_back(s1);
            s1 = "";
            continue;
        }
        else if (s[i] == '.' && s1 == ".")
        {
            if (org.size())
                org.pop_back();
        }
        else
        {
            s1 += s[i];
        }
    }
    if (s1 == "..")
    {
        org.pop_back();
    }
    else if (s1 == ".")
        ;
    else if (s1 != "")
    {
        org.emplace_back(s1);
    }
    for (int i = 0; i < n; ++i)
    {
        vector<string> v;
        string str, cur = "";
        cin >> str;
        int len = str.size();
        for (int j = 0; j < len; ++j)
        {
            if (str[j] == '/')
            {
                if (cur != "." && cur != "")
                    v.emplace_back(cur);
                cur = "";
                continue;
            }
            else if(j==0&&str[j]!='/'){
                for(auto item:org){
                    v.emplace_back(item);
                }
                if(str[1]=='.'){
                    v.pop_back();
                }
            }
            else if (str[j] == '.' && cur == ".")
            {
                if (v.size())
                    v.pop_back();
            }
            else
            {
                cur += str[j];
            }
        }
        if (cur == "..")
        {
            v.pop_back();
        }
        else if (cur == ".")
            ;
        else if (cur != "")
        {
            v.emplace_back(cur);
        }
        if (str[0] == '/' && v.size() == 0)
            cout << "/";
        else
            for (auto t : v)
            {
                cout << "/" << t;
            }
        printf("\n");
    }
}