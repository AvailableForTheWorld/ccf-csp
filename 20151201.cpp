#include<iostream>
using namespace std;
int main(){
    string s;
    int sum = 0;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; ++i){
        sum += s[i] - '0';
    }
    cout << sum;
}