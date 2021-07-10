#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
struct node {
    int va;
    node *next;
    node():next(nullptr){}
}nd[101];
int main(){
    int m, n;
    cin >> m >> n;
    vector<string> v;
    // vector<int> val(m, -1);
    string s;
    getchar();
    for (int i = 0;i<m;++i){
        node *p = &nd[i];
        getline(cin, s);
        v.push_back(s);
        int pos = s.find("{{ ",0);
        while(pos!=string::npos){
            node *q = new node;
            q->va = pos + 3;
            p->next = q;
            p = p->next;
            pos = s.find("{{ ", pos + 3);
        }
    }
    map<string,string> bl;
    for (int i = 0;i<n;++i){
        getline(cin, s);
        int v_len, s_start, s_len,flag=1,first=1;
        for (int j = 0; j < s.size();++j){
            if(first&&s[j]==' '){
                v_len = j;
                first = 0;
            }
            else if(flag&&s[j]=='"'){
                s_start = j + 1;
                flag = 0;
            }
            else if(s[j]=='"'){
                s_len = j - s_start;
                break;
            }
        }
        bl[s.substr(0, v_len)] = s.substr(s_start, s_len);
    }
    for (int i = 0;i<m;++i){
        node *p = &nd[i];
        int t = 0;
        if(p->next){
            while(p->next){
                int j;
                p->next->va += t;
                for (j = p->next->va; v[i][j] != ' ';++j)
                    ;
                string str = bl[v[i].substr(p->next->va, j - p->next->va)];
                v[i].replace(p->next->va - 3, j + 6 - p->next->va, str);
                t += str.size()-j-6+p->next->va;
                p = p->next;
            }
            cout << v[i] << endl;
        }
        else
            cout << v[i] << endl;
    }
    return 0;
}