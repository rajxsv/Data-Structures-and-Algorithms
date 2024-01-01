#include <iostream>
#include <stack>
#include <climits>
using namespace std;

int main(){

	long long n;
	cin>>n;

	long long arr[n];
	
	for(long long i=0;i<n;i++){
		cin>>arr[i];
	}

	long long i=0,area,max_area=INT_MIN;
	stack <long long> s;
	
	while(i<n){
		if(s.empty() || arr[s.top()]<=arr[i]){
			s.push(i++);
		}
		else{
			long long tp=s.top();
			s.pop();

			area = arr[tp]*(s.empty()?i:i-s.top()-1);

			max_area=max(area,max_area);
		}
	}

	while(!s.empty()){
		long long tp=s.top();
			s.pop();

			area = arr[tp]*(s.empty()?i:i-s.top()-1);

			if(area>max_area){
				max_area=area;
			}
	}

	cout<<max_area;
	
	return 0;	
}
//-------*******brute force**************

/*int largestRectangleArea(vector < int > & heights) {
  int max_area = 0;
  for (size_t i = 0; i < heights.size(); i++) {
    for (size_t j = i; j < heights.size(); j++) {
      int min_height = INT_MAX;
      for (size_t k = i; k <= j; k++) {
        min_height = min(min_height, heights[k]);
      }
      max_area = max(max_area, min_height * (j - i + 1));
    }
  }
  return max_area;
}*/

/******************Divide and Conquer**********************/

int calculateArea(vector < int > & heights, int start, int end) {
  if (start > end) {
    return 0;
  }

  int min_index = start;
  
  for (int i = start; i <= end; i++) {
    if (heights[min_index] > heights[i]) {
      min_index = i;
    }
  }
		
  return max({
    heights[min_index] * (end - start + 1),
    calculateArea(heights, start, min_index - 1),
    calculateArea(heights, min_index + 1, end)
  
  });
}
 
int largestRectangleArea(vector < int > & heights) {
  return calculateArea(heights, 0, heights.size() - 1);
}
