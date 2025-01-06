#include <bits/stdc++.h>

using namespace std;

class fenwickTree {
public:
    vector<int> fen;
    int size;

    fenwickTree(vector<int> nums) {
        this->size = nums.size();
        fen.resize(size+1);
        for(int i=0; i<size; i++) {
            update(i+1,nums[i]);
        }
    }

    void update(int i, int add) {
        while(i<size) {
            fen[i] += add;
            i += i&-i;
        }
    }

    int sum(int i) {
        int sum = 0;
        while(i > 0) {
            sum += fen[i];
            i -= i&(-i);
        }
        return sum;
    }

};

int main() {
    std::vector<int> v = {1,2,3,4,5};
    fenwickTree ft(v);

    cout << ft.sum(4) << endl;

    return 0;
}