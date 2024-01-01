#include <iostream>
using namespace std;

// ! collisions cannot be avoided but its chances of colliding should reduce
// ! hash function should make use of all the range of table size giving a more uniform distribution


// ! hash function should not use a number as simple as 10 as
// ! we can have many values of its multiplee so we use a prime number

// ! annagrams can match to same index if we just add all char values
// ! small strings wint use all the table

// ! treat each character as base 27 character and maybe use first 3
// ! abc = a + b*27 + c*27*27 . now ,amy strings can have the same prefix

// ! so we wont to use all 
// ! what we do is we use all N characters of string as an N-diit base-K number
// ! choose k to be larger thn 27 and prime 29,31,37


// ! lets talk collision handling 
// ! Collision handling schemes = 1.Open Hashing - Seperate Chaining
						   // ! = 2.Closed Hashing-Open Addressing (Linear Probing,Quadratic Probing)
						   // ! = 3.Double Hashing
// ! we do seperate chaining 
   // ! implemented using linked List
   // ! ley l is stored in T[j(k)]
   // ! if we have too many collisions and i have to search an element then maybe i have to traverse the linked list
   // ! we need to make sure linked list remains of very short length we will do rehashing !

template<typename T>
class Node{
public:
	string key;
	T value;
	Node<t>* next;

	Node(string key,T val){
		this->key = key;
		value = val;
		next = NULL;
	}
	~Node(){
		if(next!=NULL){
			delete next; // recursive destructor call
		}
	}
};

template<typename T>
class hashtable{
private:
	Node<t> **table;
	int current_size;
	int table_size;

	int hashfn(string key){
		int idx = 0;
		int p = 1; // ! powers of your number
		
		for(int j=0;j<key.length();j++){
			ind += (key[j]*p)%table_size;
			ind %= table_size;
			
			p*=27;
			p%=table_size;  // to stop overflow 
		}
		return idx;
	}

public:
	hashtable(int ts=7){
		table_size = ts;
		table = new Node<T>*[table_size];
		
		// ! int *n = new int[10]
		// ! int **n = new int*[10]

		current_size = 0;

		for(int i=0;i<ts;i++){
			table[i] = NULL;
		}
	}
	// ! key -> hashfn -> ind -> insert in table[ind]
	void insert(steing key,T value){
		int idx = hashfn(key);
		Node<T> *n = new Node<T>(key,value); // ! remember this crucial step of doing Node<T> in new

		n->next = table[idx];
		table[idx] = n; // ! insert at head
	}
	void print(){
		// ! not a part 
		for(int i=0;table_size;i++){
			cout<<"Bucket "<<i<<" ->";
			Node<T>* temp = table[i];
			while(temp!=NULL){
				cout<<temp->key << "->";
				temp = temp->next;
			}
		} 
	}

	T search(string key){

	}
	void erase(string key){

	}
}
