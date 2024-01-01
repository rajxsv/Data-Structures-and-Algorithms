#include<iostream>
using namespace std;
int main(){
    char s1[]={'a','b','c','d','e'}; //does not terminate with a null so you also get garbage in output
    char s2[]={'a','b','c','d','e','\0'};//ends with null works fine
    
    cout <<s1<<" size of s1 is "<<sizeof(s1) <<endl <<s2<<" size of s2 is "<<sizeof(s2);
    //observe the size if null is not there output is garbage and the size is that of the array intialised
    
    char s3[]="hello";
    //a different case here the language automatically puts \0 and makes it fine
     
    cout <<endl<< s3<<" size of s3 is "<<sizeof(s3);
    //size is 6 as one size of \0
    
    char s4[]={'h','e','l','l','o'};//again garbage + size of initialisation
    
    cout <<endl<< s4<<" size of s4 is "<<sizeof(s4);
    cout<<endl<<s1[1];//works just like an array!
    
    char s5[100];
    
    cin >>s5;
    cout << sizeof(s5)<<" " << s5;
    
    return 0;
    //if we use cin for initialization it also works fine automatically
}