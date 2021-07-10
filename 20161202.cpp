#include<iostream>
using namespace std;
int main(){
    int a[7] = {3500, 5000, 8000, 12500, 38500, 58500, 83500};
    double b[7] = {0.03, 0.1, 0.2, 0.25, 0.3, 0.35, 0.45};
    int salary,i;
    cin >> salary;
    for (i = 0; i < 6;++i){
        if(salary>a[i]&&salary<a[i+1]){
            salary = (salary - a[i]) / (1-b[i]) +a[i];
        }else if(salary>a[i]){
            salary += (a[i + 1] - a[i]) * b[i];
        }
        else if(salary<a[i])
            break;
    }
    if(i==6){
        salary = (salary - a[i]) / 0.55 + a[i];
    }
    cout << salary;
    return 0;
}