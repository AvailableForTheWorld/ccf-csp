#include<iostream>
#include<vector>
using namespace std;
int main(){
    int ystart,yend,week=2,a,b,c;
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> a >> b >> c;
    cin >> ystart>>yend;
    vector<int> v;
    for (int i = 1850; i < yend;++i){
        if(i%4==0&&i%100||i%400==0)
            week = (week + 2) % 7;
        else
            week = (week + 1) % 7;
        if(i>=ystart-1)
            v.emplace_back(week);
    }
    int len = v.size();
    for (int i = 0; i < len;++i){
        int t = ystart + i,cur=v[i],date=1,sum=0,nb=b;
        if(t%4==0&&t%100||t%400==0)
            month[2] = 29;
        else
            month[2] = 28;
        for (int j = 1; j < a; ++j)
        {
            cur = (cur + month[j]) % 7;
        }
        if(cur%7==0)
            cur = 7;
        // if(cur==c)
        //     --nb;
        for (int j = 1; j < nb;++j){
            sum += 7;
        }
        sum += (c - cur + 7) % 7;
        if(sum>=month[a])
        {
            cout << "none" << endl;
            continue;
        }
        date += sum;
        printf("%04d/%02d/%02d\n", ystart + i, a, date);
    }

}