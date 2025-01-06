#include <vector>
#include <iostream>
using namespace  std;

void solve(int dec, vector<int> &b6) {
    if (dec!=0){
        while(dec>0){
            b6.push_back(dec%6);
            dec/=6;
        }
    } else b6.push_back(0);
}
vector <int>solution(vector<bool>base2) {
    int dec= 0;
    vector<int> b6;
    for (int i =0;i<base2.size();i++)dec =dec*2+ (base2[i] ? 1 : 0);
    solve(dec,b6);
    reverse(begin(b6), end(b6));
    return b6;
}
int main() {
    vector<bool> base2 = {true, false, true, true, true, false, false, false, true, false, true, false, false, true, true, true};
    vector<int> b6 = solution(base2);
    for (int digit : b6) {
        cout << digit << " ";
    }

    return 0;
}