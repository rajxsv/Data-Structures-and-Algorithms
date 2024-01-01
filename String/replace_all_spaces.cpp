#include <iostream>
#include <string.h>
using namespace std;

const int N = 0;

int main()
{
    char str[1000];

    cin.getline(str,1000);

    char* ptr = strtok(str," ");
    cout << ptr << "%20";
    while(ptr!=NULL)
    {
        ptr = strtok(NULL," ");
        cout << ptr << "@40";
    }

    return 0;
}