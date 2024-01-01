#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool f(){
    string s;
    cin>>s;

    stack<char> st;

    for(auto ch : s){
        if(ch==')'){
            char top = st.top();
            st.pop();

            if(top == '('){
                return true;
            }

            while(st.top()!='('){
                st.pop();
            }
            st.pop();
        }
        else{
            st.push(ch);
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        if(f()){
            cout<<"Duplicate"<<endl;
        }else{
            cout<<"Not Duplicates"<<endl;
        }
    }

    return 0;
}

