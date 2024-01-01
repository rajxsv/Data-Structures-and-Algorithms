#include <iostream>
using namespace std;

void selec_sort(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {   //  we take one element and swap it with the smallest element ahead of it
        // this way maintain a sorted an unsorted portion of array
        // opposite to bubble sort here sorted part is created towards the right
        int index_now = i;
        for (int j = i; j <= n - 1; j++){   
            if (a[j] < a[index_now]){   
                // accordingly we have used the if statement only making changes if the new index digit is smaller than the before;
                index_now = j;
            }
        }
        
        swap(a[i], a[index_now]);
    }
}

int main(){
    int n;
    cin >> n;
    int a[1000] = {0};
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    selec_sort(n, a);

    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
