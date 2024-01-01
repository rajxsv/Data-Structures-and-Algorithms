// binary as search is between 2 numbers always
#include <iostream>
using namespace std;

int binary_search(int n, int key, int a[])
{
   int s = 0, e = n - 1, m = 0;
   while (s <= e){
      m = (s + e) / 2;

      if (a[m] == key){
         return m;
      }
      else if (a[m] > key){
         e = m - 1;
      }
      else{
         s = m + 1;
      }
   }
   return -1;
}
int main(){
   int n, key;
   int a[1000];
   
   cin >> n;
  
   for (int i = 0; i < n; i++){
      cin >> a[i];
   }
   cout << "Enter the key";
   cin >> key;
   cout << binary_search(n, key, a) << " Is the index of " << key;

   return 0;
}