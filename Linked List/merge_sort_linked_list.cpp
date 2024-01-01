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
node* find_mid(node* &head){
	node* slow = head;
	node* fast = head->next;
	while(fast && fast->next){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}
node* merge_sort(node* &head){
	//base case
	if(!head|| !head->next){
		return head;
	}
	// rec case
	// divide the list
	node* mid = find_mid(head);
	node* b=mid->next;
	
	node* a=head;
	mid->next=NULL;
	
	merge_sort(head);
	merge_sort(b)
	
	return merge(a,b);

	// you can also do
	//node *n=mid->next;
	// mid->next=NULL;
	// return merge(merge_sort(head),merge_sortt(n));
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

	node* head=NULL;
	cin >> head;
	head=merge_sort(head);
	cout<<head;

	return 0;
}