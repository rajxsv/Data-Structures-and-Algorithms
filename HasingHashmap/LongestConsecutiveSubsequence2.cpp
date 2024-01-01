#include<iostream>
#include <unordered_map>
using namespace std;

//the first approach is sort and make consecutive window
//the second is iterate from i=min to i=max and count++ eles count = 0
// we have the hashing method storing streaks

int findLargestSeq(int arr[],int n){
    unordered_map <int,int> m; //streaklength and element
    
    for(int i=0;i<n;i++){
        int no = arr[i];

        if(m.count(no-1)==0 && m.count(no+1)==0){
            //simplest case add new len
            m[no] = 1;
        
        }else if(m.count(no-1) && m.count(no+1)){
            //both are present
            int oldLen1 = m[no-1];
            int oldLen2 = m[no+1];

            int newStreak =  oldLen1 + 1 + oldLen2;

            //update the starting and ending of the old streak
            m[no-oldLen1] = newStreak;
            m[no+oldLen2] = newStreak;

        }else if(m.count(no-1)){
         
            int oldLen = m[no-1];   // 1 2 3   [4]

            m[no-oldLen]= oldLen + 1;  //update the starting of (old) new that is now
            m[no] = oldLen + 1;   //update the ending of (old) now new that is current
        
        }else{
        
            int oldLen = m[no+1];

            m[no] = oldLen + 1;
            m[no+oldLen] = oldLen + 1;
        }

    }
    int largest = 0;

    for(auto p: m){
        largest = max(largest,p.second);
    }

    return largest;
}`

int main(){

    int arr[] = {1,2,0,1};

    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<findLargestSeq(arr,n)<<endl;

    return 0;
}
