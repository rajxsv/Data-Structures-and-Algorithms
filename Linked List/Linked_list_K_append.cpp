#include <iostream>
#include <list>
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
void takeinput(int n,node* &head){
	int data;
	node* temp = head;
	while(n--){
		cin>>data;
		if(head==NULL){
			temp=new node(data);
			head=temp;
		}
		else{
			temp->next=new node(data);
			temp=temp->next;
		}
	}
}
void print(node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	// cout << "NULL";
}

// istream& operator>>(istream &cin,node* &head){
// 	takeinput(head);
// 	return cin;
// }
// ostream& operator<<(ostream &cout,node* head){
// 	print(head);
// 	return cout;
// }
void appendK(int n1,node* &head,int k){
	int itr;
	if(k<n1)itr = n1-k;
	else if(k>n1)itr=n1 - k%n1;
	else return;
		
		node* c = head;
		node* p = NULL;

		while((itr--)){
			p=c;
			c=c->next;
		}
		p->next=NULL;

		node* n=c;
		while(n->next!=NULL){
			n=n->next;
		}
		n->next=head;
		head=c;
	return;
}
int main(){	
	node* head = NULL;

	int n;
	cin>>n;
	
	takeinput(n,head);
	
	int k;
	cin>>k;
	
	appendK(n,head,k);
	print(head);

}