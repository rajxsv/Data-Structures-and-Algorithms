#include<iostream>
using namespace std;


bool validate(string check){
    if(check.size() == 0 || (check.size() > 1 && check[0] == '0')){
        return false;
    }
    int num = stoi(check);
    return  num>=0 && num<=255;
}
    
int isValid(string s) {
    // code here
    int n = s.size();
    string check = "";
    int dot = 0;
    
    for(int i=0; i<n; i++){
        if(s[i] != '.'){
            cout << "adding " << s[i] << endl;
            check += s[i];
            cout << check << endl;
        }else{
            cout << check << endl;
            if(validate(check) == false){

                return 0;
            }
            check = "";
            dot++;
            if(dot > 3){
                return 0;
            }
        }
    }
    
    if(dot!=3){
        return 0;
    }
    return 1;
}


int main(){
    string s = "192.192.321.000100";
    cout << isValid(s);
}