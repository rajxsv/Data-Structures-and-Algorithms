#include<iostream>
using namespace std;

int seg[100005], a[10000];

void build(int ind, int left, int right) {
    if (left == right) {
        seg[ind] = a[left];
        return;
    }

    int mid = (left + right) / 2;

    build(2*ind+1, left, mid);
    build(2*ind+2, mid+1, right);

        seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
}

int query(int ind, int left, int right, int l, int r) {
    if (l<=left && r>=right) return seg[ind]; // when the ST range lies completely within my wanted range
    if (l>right || r<left) return INT_MIN;

    int mid = (left+right) / 2;

    int leftRes = query(2*ind+1, left, mid, l, r);
    int rightRes = query(2*ind+2, mid+1, right, l, r);

    return max(leftRes, rightRes);
}


int main () {
    int n, q, l, r;

    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    build(0, 0, n-1);
    cin >> q; 

    for (int i=0; i<q; i++) {
        cin >> l >> r;
        cout << query(0, 0, n-1, l, r) << endl;
    }

    return 0;
}