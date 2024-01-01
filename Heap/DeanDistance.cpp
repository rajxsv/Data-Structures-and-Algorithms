#include<iostream>
#include<queue>
#include<math.h>

using namespace std;
#define ll long long 

// void f(){
//     // ! The brute way 

//      while(q--){
//         ll type,x,y;
//         cin>>type;

//         if(type==1){
//             cin>>x>>y;
//             pq.push((x*x)+(y*y));

//         }else{
//             vector<ll> aux;
//             for(ll i=1;i<k;i++){
//                 aux.push_back(pq.top());
//                 pq.pop();
//             }
            
//             cout<<pq.top()<<endl;

//             for(auto i:aux){
//                 pq.push(i);
//             }

//         }
//     }    
// }


int main(){

    priority_queue<ll> pq;

    ll q,k;

    cin>>q>>k;

    while(q--){
        ll type,x,y;
        cin>>type;

        if(type==1){
            cin>>x>>y;
            if(pq.size()>=k){
                if((x*x)+(y*y)<pq.top()){
                    pq.pop();
                    pq.push((x*x)+(y*y));
                    // cout<<pq.top()<<endl;
                }
            }else{
                pq.push((x*x)+(y*y));
                // cout<<pq.top()<<endl;
            }
        }else{
            cout<<pq.top()<<endl;
        }     
    }

    return 0;
}