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
void insert_at_tail(node* &head,int d){
	if(head==NULL){
		head = new node(d);
		return;
	}

	node* temp = head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next = new node(d);
	return;
}
void print(node* &head){
	node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL\n";
}
void make_new_user_list(node* &head){
	int n;
	cin >> n;
	int data;

	for(int i=0;i<n;i++){
		cin >> data;
		insert_at_tail(head,data);
	}
}
int list_len(node* head){
	if(head==NULL)return 0;
	if(head->next==NULL)return 1;

	int len=0;
	while(head!=NULL){
		len++;
		head=head->next;
	}
	return len;
}
void reverse(node* &head){
	if(head==NULL){
		return;
	}
	node* prev=NULL;
	node* curr=head;

	while(curr!=NULL){
		node* temp = curr->next;
		curr->next=prev;

		prev=curr;
		curr=temp;
	}
	head=prev;
}
void kth_node(node* head){
	int k;
	cin >> k;

	int len = list_len(head);
	
	reverse(head);
	int node_no=1;

	while(node_no<=k){
		node_no++;

		if(node_no<k)
		head=head->next;
	}
	cout<<k<<"th node = "<<head->data<<endl;
}
int main(){

	node* head = NULL;
	make_new_user_list(head);
	print(head);
	kth_node(head);

	return 0;
}