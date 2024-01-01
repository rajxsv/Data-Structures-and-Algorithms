#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1 , pair<int,int> p2)
{   
   if(p1.first == p2.first)
   {
       return p1.second >= p2.second;
   }
 
    return p1.first > p2.first; //in sort naturally we have a<b condition whereas in bubble sort a >= b is there
} 

int main()
{

    vector <pair<int,int>> v  ;

    for(int i = 0 ; i < 4 ;i++)
    {
        int x , y;
        cin >> x >> y;

        v.push_back(make_pair(x,y));
    }

    sort(v.begin() , v.end() , compare );

    for(int i = 0 ; i < 4 ; i++)
    {
        cout << v[i].first << " "<<v[i].second<<endl;
    }

    return 0;
     
}