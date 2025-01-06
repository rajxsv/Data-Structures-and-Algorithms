#include <iostream>
#include <cmath>
using namespace std;

double solution(int hour, int minute, int second) {
    hour=(hour==12?0:hour);
    double ma= (minute *6)+(second*6.0/ 60);
    double ha =(second*0.5/60)+(minute* 0.5) +(hour*30);
    double a= abs(ha-ma);
    if (a<360-a)return a;
    return  360-a;
}   

int main() {
    int hour = 3;
    int minute = 15;
    int second = 0;

    cout << solution(hour, minute, second) << endl;
    return 0;
}