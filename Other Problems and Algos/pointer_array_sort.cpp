#include<iostream>
#include<algorithm>
using namespace std;
int n;
    
void print(int* pptr){
    int k = 0;
    while((pptr + k)<=(pptr + (n-1))){
        cout<< *(pptr+k);
        k++;
    }
}

int sort(int* ptr)
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i ; j < n ; j++)
        {
            if(*(ptr+j)< *(ptr+i))
            {
            swap(*(ptr+j),*(ptr+i));
            }
        }
    }
    print(ptr);
    return 1;
}



int main()
{
    
    cin >> n;
    int arr[n],i=0;

    while(arr+i<=(arr+(n-1))){
        cin >> *(arr + i);
        i++;
    }
    sort(arr);
    return 0;
}