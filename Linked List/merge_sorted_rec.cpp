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
node* merge(node* head1,node* head2){
	if(head1==NULL){
		return head2;
	}
	if(head2==NULL){
		return head1;
	}
	// rec case
	node* c;
	if(head1->data<head2->data){
		c=head1;
		c->next=merge(head1->next,head2);
	}
	else{
		c=head2;
		c->next=merge(head1,head2->next);
	}
	return c;
}
istream& operator>>(istream &cin,node* &head){
	takeinput(head);
	return cin;
}
ostream& operator<<(ostream &cout,node* head){
	print(head);
	return cout;
}
int main(){

	node* head1=NULL;
	node* head2=NULL;
	cin>>head1>>head2;
	node*head3=merge(head1,head2);
	cout<<head3;

	return 0;
}