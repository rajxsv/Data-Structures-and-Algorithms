#include <iostream>
#include <cstring>
using namespace std;
void removeduplicate(char s[])
{
    int prev = 0;
    int l = strlen(s);
    if (l == 0 || l == 1)
    {
        return;
    }
    for (int current = 1; current < l; current++)
    {
        if (s[current] != s[prev])
        {
            prev++;
            s[prev] = s[current];
        }
    }
    s[prev + 1] = '\0';
    return;
}

int main()
{
    char s[1000];
    cin.getline(s, 1000);

    removeduplicate(s);

    cout << s;
    return 0;
}