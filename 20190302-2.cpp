#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    for (int j = 0; j < n;++j){
        string s;
        cin >> s;
        int val=0;
        int len = s.size();
        vector<int> add,mul,num(4);
        for (int i = 0; i < 4;++i){
            num[i] = s[2 * i]-'0';
        }
        int t=3;
        while(t--){
            int id1 = s.find('+'), id2 = s.find('-'), id3 = s.find('*'), id4 = s.find('/');
            
        }
    }
}