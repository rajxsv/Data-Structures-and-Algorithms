#include<iostream>
using namespace std;
class node{
public:
	int data;
	node* next;

	node(int d){
		data=d;
		next=NULL;
	}
};
void takeinput(node* &head){
	int data;
	cin >> data;
	node* temp = head;
	while(data!=(-1)){
		if(head==NULL){
			temp=new node(data);
			head=temp;
		}
		else{
			temp->next=new node(data);
			temp=temp->next;
		}
		cin>>data;
	}
}
void print(node* head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout << "NULL";
}

istream& operator>>(istream &cin,node* &head){
	takeinput(head);
	return cin;
}
ostream& operator<<(ostream &cout,node* head){
	print(head);
	return cout;
}
bool is_cycle(node* head){
	
	node* slow=head;
	node* fast=head;

	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow){
			return true;
		}
	}
	return false;
}
void removecycle(node* &head){
	node* slow=head;
	node* fast=head;

	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow){
			break;
		}
	}
	slow=head;
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next;
		if(slow->next==fast->next){
			break;
		}
	}
	fast->next=NULL;
	cout<<"in remove Cycle\n";
}
int main(){

	node* head=NULL;
	cin >> head;
	node* temp = head;
	
	while(temp->next!=NULL){
		temp=temp->next;
	}

	temp->next=head;
	
	node* n1= new node(1);
	node* n2= new node(2);
	node* n3= new node(3);
	n1->next=n2;
	n2->next=n3;
	n3->next=head;
	
	bool iscycle = is_cycle(n1);
	if(iscycle){
		removecycle(n1);
	}
	cout<<n1;

	return 0;
}