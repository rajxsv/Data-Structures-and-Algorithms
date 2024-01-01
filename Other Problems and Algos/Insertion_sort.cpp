#include <iostream>
using namespace std;
void ins_sort(int n, int a[])
{
    for (int i = 1; i < n; i++)
    {
        int check_element = a[i];
        int j = i - 1;
        while (j >= 0 and a[j]>check_element)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = check_element;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[1000] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ins_sort(n, a);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
