#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        stack<int> num, st;
        int len = s.length(), val;
        for (int j = 0; j < len; ++j)
        {
            if (s[j] >= '0' && s[j] <= '9')
            {
                num.push(s[j] - '0');
            }
            else
            {
                switch (s[j])
                {
                case '+':
                case '-':
                    if(!st.empty())
                    {
                        int flag = st.top(),v2,v1;
                        v2 = num.top();
                        num.pop();
                        v1 = num.top();
                        num.pop();
                        if (flag == 1) 
                            val=v1+v2;
                        else if (flag == 2)
                            val=v1-v2;
                        num.push(val);
                        st.pop();
                    }
                    if(s[j]=='+')
                        st.push(1);
                    else
                        st.push(2);
                    break;
                case 'x':
                case '/':
                    val = num.top();
                    num.pop();
                    if(s[j]=='x')
                        val *= (s[j+1] - '0');
                    else 
                        val /= (s[j+1] - '0');
                    ++j;
                    num.push(val);
                    break;
                }
            }
        }
        while(!st.empty()){
            int j = st.top(),v1,v2;
            st.pop();
            v2 = num.top();
            num.pop();
            v1 = num.top();
            num.pop();
            if(j==1){
                num.push(v1 + v2);
            }
            else if(j==2){
                num.push(v1 - v2);
            }
        }
        if (num.top() == 24)
        {
            printf("Yes\n");
        }
        else
            printf("No\n");
    }
    return 0;
}