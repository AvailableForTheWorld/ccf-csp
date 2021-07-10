#include<iostream>
using namespace std;
int main(){
    int year, day,a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    cin >> year >> day;
    if(year%4==0&&year%100||year%400==0)
        ++a[1];
    int month = 1,i=0;
    while(day-a[i]>0){
        ++month;
        day -= a[i];
        ++i;
    }
    printf("%d\n%d", month, day);
}