#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
    string s, c="", nc="", x;
    cin >> s;
    int len = s.size();
    for (int i = len - 1; i >= 0; --i){
        if(s[i]==':')
        {
            c += s[i - 1];
            --i;
        }
        else
            nc += s[i];
    }
    int n;
    cin >> n;
    getchar();
    map<char, string> mp;
    for (int j = 0; j < n; ++j){
        getline(cin, x);
        mp.clear();
        int lenx = x.size(),flag=1,judge=0;
        for (int i = 0; i < lenx;++i){
            if(flag&&x[i]!=' ')
                continue;
            else if(x[i]==' ')
            {
                flag = 0;
                continue;
            }
            else if(x[i]=='-'){
                if(i<lenx-2&&x[i+2]!=' '||c.find(x[i+1])==string::npos&&nc.find(x[i+1])==string::npos)
                {
                    judge = 1;
                    break;
                }else if(c.find(x[i+1])==string::npos){
                    if(i<lenx-3&&x[i+3]!='-')
                    {
                        judge = 1;
                        break;
                    }
                    mp[x[i + 1]] = "";
                    ++i;
                }else if(nc.find(x[i+1])==string::npos){
                    if(i>=lenx-3){
                        judge = 1;
                        break;
                    }
                    string xt = "";
                    int k;
                    for (k = i + 3; x[k] != ' '&&k<lenx; ++k){
                        xt += x[k];
                    }
                    mp[x[i + 1]] = xt;
                    i = k;
                }
            }
        }
        printf("Case %d:", j+1);
        for(auto z:mp){
            if(z.second.size()==0)
                cout <<" -" << z.first ;
            else
                cout <<" -" << z.first << " " << z.second ;
        }
        printf("\n");
    }
    return 0;
}