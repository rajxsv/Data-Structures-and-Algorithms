#include<iostream>
using namespace std;
void fun(int *x , int *y){
    cout << *x <<" "<< *y <<endl;
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}
int ain(){
    nt x = 10 , y = 20 ;
    un (&x,&y);
    nt a = 10 ;
    out << x << " " << y << endl ;
    /pointer takes only integer output
    nt *aptr = &a ;  //aptr without * gives me address
    out  << a << endl << aptr << endl << *aptr << endl << &a ; 
    eturn 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        