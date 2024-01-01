// isnpired from boiling water
#include <iostream>
#include<algorithm>

using namespace std;
bool compare(int a, int b){
    // cout << "comparing " << a << "," << b << endl;
    return a > b;
}

void bubble_sort(int n, int a[], bool (&cmp)(int , int )){
    for (int i = 1; i <= n - 1; i++){
        for (int j = 0; j <= n - 1 - i; j++){
            if (cmp(a[j], a[j + 1])){
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int a[1000] = {0};
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    // bubble_sort(n, a, compare);
    sort(a,a+n,compare);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ,";
    }
    return 0;
}
