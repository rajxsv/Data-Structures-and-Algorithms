
#include <iostream>
using namespace std;

string solution(const string &s)
{
    int s_size = s.size();
    // start position and length of the longest sequence
    // which doesn't contain 3 contiguous occurrences of a and b
    int start_ml = 0, max_length = 0; // start of current processing string of the same letters.
    int start = 0;                    // length of current processing string of the same letters.
    int count = 1;
    for (int i = 1; i < s_size; ++i)
    {
        if (s[i] == s[i - 1])
        {
            // if we met two the same
            // letters increase the counter of the same letters
            count++;
        }
        else
        {
            // if next letter is different drop the counter to 1
            count = 1;
        }
        if (count <= 2)
        {
            // if the sequence of different letters continuing,
            // set it's current length as
            // max_length if it is bigger than current max_length
            // "i - start + 1" is length of the current
            // processed sequence
            if (i - start + 1 > max_length)
            {
                max_length = i - start + 1;
                start_ml = start;
            }
        }
        else
        {
            // if the sequence of the same letters continuing,
            // move the pointer to points to the last two
            // chars of this sequence
            // drop the count to 2
            start = i - 1;
            count = 2;
        }
    }
    return s.substr(start_ml, max_length);
}

string mySoln(string s){
    int n = s.size();
    int start = 0;
    int c = 0;

    char prev = s[0];

    string ans = "";

    for(int i=0;i<n;i++){
        if(s[i] == prev && c<2){
            c++;
        }else if(s[i] == prev){
            i = start+1;
            start = i;
            c=1;
            prev = s[i];
        }else{
            prev = s[i];
            c = 1;
        }
        if(i-start+1 > ans.size()){
            ans = s.substr(start,i-start+1);
        }
    }
    return ans;
}

int main()
{
    string s = "aaaaaaaaaaaaaaaaabbaabbaabbaa";
    cout << solution(s) << endl;
    cout << mySoln(s) << endl;

    return 0;
}