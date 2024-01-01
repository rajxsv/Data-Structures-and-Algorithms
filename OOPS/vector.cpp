#include <iostream>
using namespace std;
template <typename T>
class myvector{
public:
	int size;
	int total_size;
	T *ptr;

	myvector(myvector &v){
		size=v.size;
		total_size=v.total_size;
		ptr = new T[total_size];
		for(int i=0;i<size;i++){
			ptr[i] = v.ptr[i];
		}
	}

	myvector(T n=2){
		total_size=n;
		ptr = new T[n];
		size=0;
	}
	void print(){
		for(int i=0;i<size;i++){
			cout<<ptr[i]<<" ";
		}
		cout<<endl;
	}
	void pushbac(T ele){
		if(size==total_size){
			T* new_ptr = new T[2*total_size];
			total_size*=2;

			for(int i=0;i<size;i++){
				new_ptr[i]=ptr[i];
			}
			new_ptr[size++]=ele;
			for(int j=size+1 ;j<total_size;j++){
				new_ptr[j]=0;
			}

			ptr=new_ptr;
		}
		else{
			ptr[size++]=ele;
		}
	}
	T& operator[](int index){
		return ptr[index];
	}

	void operator+(myvector &add){
		int temp=size;
		size = size + add.size;
		while(size>total_size){
			total_size*=2;
		}

		int i=temp;
		int j=0;
		while(i<size && j<add.size){
			ptr[i++]=add.ptr[j++];
		}
	}
};

ostream& operator << (ostream &os,myvector<auto> &v){
	v.print();
	return cout;
}
int main(){

	// this syntax is very imp as 
	// the <> is used for calling the template
	// and after that i have also used list initialiser
	myvector<int> v(100);
	
	v.pushbac(1);
	v.pushbac(2);
	v.pushbac(3);
	v.pushbac(4);
	v.pushbac(5);
	v[0]=100;


	v.print();
	cout<<v.total_size<<endl;

	myvector<int> v1;

	v1.pushbac(1);
	v1.pushbac(2);
	v1.pushbac(2);
	v1.pushbac(3);
	v1.pushbac(2);
	v1.pushbac(2);
	v1.pushbac(3);	
	v1.pushbac(2);
	v1.pushbac(2);
	v1.pushbac(3);
	v1[0]=100;
	v1[4]=600;
	v1[3]=200;


	v1.print();
	cout<<v1.total_size<<endl;

	myvector <char> a;
	a.pushbac('a');
	a.pushbac('b');
	a.pushbac('c');
	
	myvector <char> b(3);
	b.pushbac('d');
	b.pushbac('e');
	b.pushbac('f');

	cout << "1st = ";
	a.print();

	cout << "2st = ";
	b.print();

	// myvector <char> c;
	// c = a+b;

	a+b;

	cout << "sum = ";
	a.print();

	myvector <char> x(a);
	// why does below work?
	// as this is a valid statement
	cout;
	cout << x << a; 

	return 0;
}