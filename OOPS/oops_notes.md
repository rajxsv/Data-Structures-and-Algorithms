
## OOPS Notes 

> Good webinar [STL and classes](https://online.codingblocks.com/app/player/222697/content/217062/1210/lecture).

- Talking about **iterators** they are defined in every class and are basically `objects or entities`.
- Remember about ostream(`cout`) and istream(`cin`)
- an iterator is defined as for example for a set
 ```cpp
 set<int> set;
 //"::" this scope ressolution is basically telling use that we want the iterator from the set class
 set<int> :: iterator = it ;
 //we  can use
 set.begin();
 set.end();
 //as the starting and ending pointers
```
- A function with address return type 

```cpp
#include<iostream>
- void fun& (. . .){
    . . .
}
//notice that `&` after the function
```
---
### Some other things
```cpp
bool arr[10]=0; //a bool takes 8 bytes so this takes 80 bytes
//#include<bitset>
bitset<10> b(string("0000000000"));
//or
bitset<10> b(10) //both takes just 10 bits!
//use this instead of using bollian arrays
. 