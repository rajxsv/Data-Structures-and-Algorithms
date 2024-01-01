#include<bits/stdc++.h>
using namespace std;

int main()
{
    //1D ARRAYS----------------------------------------

    //STATIC ARRAYS
    int s[100];
    cout << "size of static declared array " << sizeof(s)<<endl;
    

    //DYNAMIC ARRAY
    int *d = new int [100];           //here new will return the address of allocated memory in heap so we are using a pointer in stack to recieve it 
    cout <<"size of dynamically declared array"<< sizeof(d); 

    int *ptr = new int[100];
    ptr[4]=7;
    cout<<ptr[4];
    //2d array -----------------------------------------

    //static
    int ars[10][20];
    

    //dynamic
    int r = 10;
    int c = 20;

    int** arn; 
    arn = new int*[r]; //IMPORTANT !!!!! here is the array of POINTERS so we need a diuble pointer 

    for(int i = 0 ; i < r ;i++)
    {
        arn[i] = new int[c];
    }

    delete[] arn;
    delete[] d;
    
    return 0;
}