#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
map<char, int>type;//记录第一行读取到的命令选项的类型
map<char, string>para;//保存选项及其参数（不带参数选项的参数记为"*")
string s, s1, s2;
int main() {
    cin >> s;
    int T;
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] != ':' && s[i + 1] == ':') {
            type[s[i]] = 1;
        }
        else if (s[i] != ':')
            type[s[i]] = 2;
    }
    if (s[s.length() - 1] != ':') type[s[s.length() - 1]] = 2;//判断最后一个字符
    cin >> T;
    cin.get();//以免读入换行符
    bool flag;
    for (int cs = 1; cs <= T; cs++) {
        getline(cin, s);//字符串读入一行的输入
        flag = 0;
        para.clear();//要注意map的初始化
        int p1, p2;
        while ((p1 = s.find(' ')) != -1) {
            s[p1] = 0;
            p2 = s.find(' ');
            if (p2 == -1) p2 = s.length();//读到字符串末尾
            s2 = s.substr(p1 + 1, p2 - p1 - 1);//保存内容
            if (!flag) {
                if (s2[0] != '-' || !type[s2[1]]) 
                    break;//如果是非法内容，直接退出循环
                if (type[s2[1]] == 2) {
                    para[s2[1]] = "*";//保存不带参数选项
                }
                else {
                    s1 = s2;//如果是带参数选项，对其另做保存
                    flag = 1;
                }
            }
            else {
                para[s1[1]] = s2;//读入参数后保存选项和参数
                flag = 0;
            }
        }
        cout << "Case " << cs << ":";
        for (map<char, string>::iterator it = para.begin(); it != para.end(); it++) {
            //输出map中保存的内容
            cout << " -" << (*it).first;
            if ((*it).second[0] != '*')
                cout << ' ' << (*it).second;
        }
        cout << endl;
    }
}