#include <iostream>
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
void takeinput(node* &head,int n){
	int data;
	node* temp=NULL;
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
}
int length(node* head){
	int len=0;
	while(head==NULL){
		head=head->next;
		len++;
	}
	return len;
}
node* krev(node* &head,int k){
	node* p=NULL;
	node* n=NULL;
	node* c=head;
	int i=k;
	while((i--) and c!=NULL){
		n=c->next;
		c->next=p;

		p=c;
		c=n;

		//remember the aim we just change one pointer one time
	}

	if(head!=NULL){
		head->next=krev(c,k);
	}
	return p;
}
int main(){
	int k,n;
	cin>>n>>k;
	node* head=NULL;
	// node* ans=NULL;
	takeinput(head,n);
	head=krev(head,k);
	print(head);

	return 0;
}