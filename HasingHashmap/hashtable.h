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
	Node<T>* next;

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

// ! Rehashing and LoadFactor

// ! inserting 20 int table_size of 10 surely will have collisions
// ! one way is increase the table_size as number of ele increase
// ! suppose in the current table has 6 ele and max is 10
// ! load Factor is ratio of cur size and table size
// ! if load factor > certain threshhold 
// ! (like .75) maybe then we can increase the table size
// ! newTableSize can be approx next prime after its double like 41
// ! then we rehash we again map all the keys to values acc to new params
// ! we delete the old table and allocate new rehashing is exprensive O(N)

template<typename T>
class hashtable{
private:
	Node<T> **table;
	int current_size;
	int table_size;

	int hashfn(string key){
		int idx = 0;
		int p = 1; // ! powers of your number
		
		for(int j=0;j<key.length();j++){
			idx += (key[j]*p)%table_size;
			idx %= table_size;
			
			p*=27;
			p%=table_size;  // to stop overflow 
		}
		return idx;
	}

	void rehash(){
		Node<T> **oldTable = table;
		int oldTableSize = table_size;
		
		table_size = 2*table_size;

		table = new Node<T> *[table_size];

		for(int i=0;i<table_size;i++){
			table[i] = NULL;
		}
		current_size = 0;

		for(int i=0;i<oldTableSize;i++){
			Node<T> *temp = oldTable[i];
			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp = temp->next;
			}
			delete oldTable[i];
		}
		delete [] oldTable; // ! making sure no mem loaks
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
	void insert(string key,T value){
		int idx = hashfn(key);
		Node<T> *n = new Node<T>(key,value); // ! remember this crucial step of doing Node<T> in new

		n->next = table[idx];
		table[idx] = n; // ! insert at head

		current_size++;

		float load_factor = current_size/table_size;
		if(load_factor>=0.75){
			rehash();
		}
	}
	void print(){
		// ! not a part just for dev purpose
		for(int i=0;i<table_size;i++){
			cout<<"Bucket "<<i<<" ->";
			Node<T>* temp = table[i];
			while(temp!=NULL){
				cout<<temp->key << "->";
				temp = temp->next;
			}
			cout<<endl;
		} 
	}

	T* search(string key){
		Node<T> *n = table[hashfn(key)];

		while(n!=NULL){
			if(n->key == key){
				return &n->value;   // ! returning value by doing & of pointer
			}
			n = n->next;
		}

		return NULL;
	}
	void erase(string key){
		int idx = hashfn(key);

		Node<T> *n = table[idx];
		Node<T> *prev = table[idx];     

		while(n!=NULL){
			if(n->key == key){
				cout<<"Found "<<key<<endl;
				if(n!=table[idx]){
					prev->next = n->next;
				}
				else{
					table[idx] = n->next;
					cout<<"in else"<<endl;
				}
				n->next = NULL;
				delete n;
				break;
			}
			prev = n;
			n=n->next;
		}
	}
	T& operator[](string key){
		T *f = search(key); // this search return the address of box and we need pointers to store addresses
		if(f==NULL){
			// garbage
			T garbage;
			insert(key,garbage);
			f = search(key);

		}
		return f; 
	}
};
