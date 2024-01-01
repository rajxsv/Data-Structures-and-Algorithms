#include <iostream>
#include <cstring>
using namespace std;

class Car{
// private:
public:
	string name;
	int model_no;
	int price;
	// suppose i need a constant variable throughout
	// i cant init it here
	const int id;  //if you are declaring a const function then you have to declare it 
	// everywhere you are contructing a car
	// const int id; allowed as ***Initisalisation***
	// id=10; not allowed as ***this is not ititialisation this is assignment***

	// this init lisr willl only work for 'Car x' 
	// basically only when constructor is called to intialise something
	Car():id(1){
		cout<<"contructor"<<endl;
	}
	// now we have done something like init in the parameters(parameterised constructor)
	// bascially we have said that by default if we dont get anything
	// init it as this else take the value recieved
	Car(int p,string s,int no,int i=1):id(i){ //so we do init list here also 
		name=s;
		model_no=no;
		price=p;
	}

	void print(){
		cout<<"Car "<<name
			<< "\nmodel_no "<<model_no
			<<"\nprice "<<price<<endl
			<<"Id "<<id<<endl;

	}

	Car(Car &z):id(1){
		cout<<"Copy operator"<<endl;
		// copy operator is also a constructor function

		// now we have declared our own we have to do write what 
		// will it do
		name=z.name;
		model_no=z.model_no;
		price=z.price;
	}

	void operator=(Car &x){
		cout<<"Copy Assignment operator"<<endl;
	}

	// const parameters and functions
	// const parameters are those paramters that do not get changed insider the function
	// const functions are those which do not update the value of any data memeber inside
	// them
	void discount_price() const{
		cout<<"the discount_price(@ 20%) of " <<name<<" is "<<price-(price*0.2)<<endl;
		return;
	}

	void name_change(string newname,const int id){
		cout<<"the new name of "<<name<<" is "<<newname<<endl;
		name=newname;
		// cant do this (why read only parameter)
		// id=10;
		return;
	}
};

int main(){

	Car a(100,"Swift",123);
	// a.id++; not allowed!
	a.print();

	Car b(200,"i10",1230,20);
	b=a;
	b.print();

	Car c=a;
	c.print();

	a.discount_price();
	b.discount_price();
	c.discount_price();

	a.name_change("i20",10);

	a.print();

}