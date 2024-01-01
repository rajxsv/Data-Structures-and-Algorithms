#include <iostream>
#include <cstring>
using namespace std;

class Car{
private:
	int price;
public: //Acess modifier
	int model_no;
	string name;
	char* tire;

	construtor function
	Car(){
		// tire=NULL;
		cout<<"Insider Constructor function"<<endl;
	}

	Car(int m_no,int p,string n,char *t){
		price=p;
		model_no=m_no;
		name = n;
		tire= new char[strlen(t)+1];
		strcpy(tire,t);
	}
	// Copy constructor 
	Car(Car &x){
		model_no=x.model_no;
		name=x.name;
		price=x.price;
		tire = new char[strlen(x.tire)+1];

		// if not adding the below line and instead doing a simple copy 
		// or using the copy constructor both cars point to the same
		// memory loc(shallow mem)
		// hence we have to make a deep copy 
		
		strcpy(tire,x.tire);
	}
	void print(){
		cout<<"Name = "<<name<<endl;
		cout<<"model_no = "<<model_no<<endl;
		cout<<"price = "<<price<<endl;
		cout<<"tire ="<<tire<<endl;
	}
	void set_price(int x){
		price = x;
	}
	void operator=(Car &x){
		cout<<"Inside copy assignment operator"<<endl;
		// copy operator
		model_no=x.model_no;
		name=x.name;
		price=x.price;
		tire = new char[strlen(x.tire)+1];
		strcpy(tire,x.tire);
	}

	void operator=(Car &x){
		model_no = x.model_no;
		name = x.name;
	}

	~Car(){
		cout<<"Destructor fn call "<<name<<endl;
	}
};

int main(){
	Car nox();//will be called by default constructor

	Car no(1,123124,"Swift","Grade 2");

	no.print();

	no.set_price(50000);
	cout<<"\nAfter setting price\n"<<endl;

	no.print();
	
	cout<<sizeof(Car)<<endl;
	cout<<sizeof(no)<<endl;

	cout<<"\n\n";
	Car no1(321,696969,"Audi","Grade 1");
	no1.print();
	
	// Consstructor function basically gets in the class and 
	// does work , either we call by ouselves or it can be called itself
	// by jus twrinting Car Car_name
	
	Car no2(123,123,"Benz","Grade 1");
	no2.print();

	cout<<"\n\n";

	Car no3 = no2;
	cout<<"Car no3 \n";
	no3.print();

	cout<<"\n\n";

	Car no4(no3);
	cout<<"Car no4 \n";
	no4.print();

	// deleting by user (calling destructrr)
	// you cannot delete a static memory variable you need to 
	// allocate it dynamically
	// delete no4; 

	Car *noq = new Car(no4); 
	// we cant use this as now we have noq as pointer and not  an object 
	// we need to get the bucket first
	// we have 2 ways
	//  -(*noq).print
		noq->print();

	// noq.print();

	// cout<<"\n\nInbuilt copy instructor "<<endl;
	no3.tire = "Grade X";
	no3.print();

	no4.print();

	cout<<"\n\n";
	
	Car no5;
	no5 = no;
	no5.print();

	return 0;
}