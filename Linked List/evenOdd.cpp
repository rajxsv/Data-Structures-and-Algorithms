#include <iostream>
using namespace std;

class node{
private:
	int data;
	node* next;
public:
	node(int dat){
		data = dat;
		next=NULL; 
	}

};

int main(){

	node* head(5) ;

	cout<<head->data;


	return 0;

}