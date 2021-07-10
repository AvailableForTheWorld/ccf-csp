#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct node{
    double p;
    int q;
} nd;
int main(){
    string s;
    double price;
    int num,line;
    map<double, int,greater<double>> buy;
    map<double,int>sell;
    vector<node> v;
    vector<int> u;
    while(cin>>s){
        if(s=="buy"){
            scanf("%lf %d", &price, &num);
            buy[price] += num;
            nd.p = price;
            nd.q = num;
            v.emplace_back(nd);
            u.emplace_back(1);
        }else if(s=="sell"){
            scanf("%lf %d", &price, &num);
            sell[price] += num;
            nd.p = price;
            nd.q = num;
            v.emplace_back(nd);
            u.emplace_back(-1);
        }else if(s=="cancel"){
            scanf("%d", &line);
            nd.p = 0;
            nd.q = 0;
            v.emplace_back(nd);
            u.emplace_back(0);
            switch(u[line-1]){
                case 1:buy[v[line - 1].p] -= v[line - 1].q;
                    break;
                case -1:sell[v[line - 1].p] -= v[line - 1].q;
                    break;
            }
        }
    }
    map<double, int> buy_final, sell_final;
    int sum=0;
    for (map<double, int>::iterator it = buy.begin(); it != buy.end();++it){
        sum += it->second;
        buy_final[it->first] += sum;
        cout << "买入：" << it->first << " " << sum << endl;
    }
    sum = 0;
    for (map<double, int>::iterator it = sell.begin(); it != sell.end();++it){
        sum += it->second;
        sell_final[it->first] += sum;
        cout << "卖出：" << it->first << " " << sum << endl;
    }
    map<double, int>::iterator it1 = buy_final.begin(), it2 = sell_final.begin();
    price = 0;
    num = 0;
    int min_num, max_num = 0;
    while (true)
    {
        if(it1==buy_final.end()||it2==sell_final.end()){
            break;
        }else if(it1->first<it2->first){
            ++it1;
        }else if(it1->first>=it2->first){
            min_num = min(it1->second, it2->second);
            if(min_num>max_num){
                price = it1->first;
                max_num = min_num;
            }
            else if(min_num==max_num){
                price = max(price, it1->first);
            }
            ++it1;
        }
    }
    printf("%.2lf %d", price, max_num);
}