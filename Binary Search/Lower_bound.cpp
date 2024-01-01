#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> nums(n);

	for(int i=0; i<n; i++){
		cin >> nums[i];
	}

	int k;
	cin >> k;

	auto it = upper_bound(nums.begin(), nums.end(), k);

	cout << *it << " " <<*(--it)<<endl;

	cout << *nums.begin() << " " << *nums.end() << endl;

	return 0;
}