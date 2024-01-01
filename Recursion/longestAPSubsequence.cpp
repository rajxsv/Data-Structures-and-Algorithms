#include <bits/stdc++.h>
using namespace std;


int solve(vector<int> nums, int i, int diff, int next){
	if(i<0){
		return 0;
	}

	int currDiff = next - nums[i];

	if(currDiff == diff){
		return 1+solve(nums, i-1, diff, nums[i]);
	}
	return max(solve(nums, i-1, diff, nums[i]) , solve(nums, i-1, currDiff, nums[i]));
}


int main(){
	vector<int> nums = {3, 6, 9, 12};

	cout << 1 + solve(nums, 2, 12-9, 12) << endl;







	/*   !     3   6   9   12   

							12-9 -> 3 add one to the answer,
							9-6 -> 3
							6-3 -> 3  
								just keep going back adding one

			   0  10  20  23 
			               23-20 = 3  we can store 2 for now
			               20 - 10  = 10  does not match 2 cases now
			               				1. either we can go on with prev diff
			               				2. we can try out with the current diff


			[20,1,15,3,10]      

	*/
	return 0;
}