## Generic Programming in C++

- Generic Programming means creating functions that are universal for any datatype we may send as arguements.
- `example` We have templates  template<typename T>   in c++ for this purpose.

***
```c++
#include<iostream>
using namespace std;
template<typename T>
void search(T arr*,int n,T key){
    for(int i=0;i<n;i++){
        if(arr[i]=key){
            return i;
        }
    }
    return -1;
}
```
***

# Containers in c++ <sub><asdasdsub>
- Sequence containers `Data structures that can be accessed in sequential manner`
    + vector
    + list `Doubly linked list`
    + deque `is a doubly linked queue`
    + array
    + Forward List  `Singly linked list`
    
- Container Adaptors : `provide a different interface for sequential containers.`
    + queue
    + priority queue `uses heap data structure`
    + stack

- Associative Contajners : `implement sorted data structures that can be quickly searched (O(logn)complexity).`
    + set
    + multiset
    + map
    + multimap
- Unordered Associative Containers : `implement unordered data structures that can be quickly
searched`
    + unordered set
    + unordered multiset
    + unordered map
    + unordered multimap

***
