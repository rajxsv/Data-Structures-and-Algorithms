#include<iostream>
#include<cstring>
using namespace std;

bool palindromic(char s[] ){
    int j;
    j = strlen(s)-1 ;
    int i = 0;
    while(j>=i){
       if(s[j]!=s[i]){
           return false;                                     //palindromic means like abba acbca;S
       }
       i++;
       j--;
    }
    return true;
}
int main(){
    char s[1000];
    cin.getline(s,1000);
    if(palindromic(s)){
        cout << "string is palindromic";
    }
    else{
        cout << "string is not palindromic";
    }
    return 0;
}