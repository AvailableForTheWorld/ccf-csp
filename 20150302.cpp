#include <iostream>
#include <map>
#include <vector>
#include<algorithm>
using namespace std;
int cmp(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}
int main()
{
    int n, t;
    cin >> n;
    map<int, int> mp;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &t);
        ++mp[t];
    }
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        v.emplace_back(*it);
    }
    sort(v.begin(), v.end(), cmp);
    for(vector<pair<int,int>>::iterator it=v.begin();it!=v.end();++it){
        printf("%d %d\n", it->first, it->second);
    }
    return 0;
}