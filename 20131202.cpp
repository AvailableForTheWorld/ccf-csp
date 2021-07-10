#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
    string s;
    cin >> s;
    int len = s.size(),ans=0,index=1;
    for (int i = 0; i < len-1; ++i)
    {
        if(isdigit(s[i])){
            ans += index * (s[i] - '0');
            ++index;
        }
    }
    char res;
    if(ans%11<10)
        res = (ans % 11)+'0';
    else
        res = 'X';
    if(res==s[len-1])
        cout << "Right";
    else
    {
        s[len - 1] = res;
        cout << s;
    }
    return 0;
}