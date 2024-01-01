#include <iostream>
using namespace std;
class node{
public:
	int data;
	node* next;

	node(int data){
		this->data=data;
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
node* merge(node* head1, node* head2){
	node* head3 = NULL;
	// a cond for NULL

	while(head1!=NULL && head2!=NULL){
		if(head1->data >= head2->data){
			insert_at_tail(head3,head2->data);
			head2=head2->next;
		}
		else{
			insert_at_tail(head3,head1->data);
			head1=head1->next;
		}
	}
	while(head1!=NULL){
		insert_at_tail(head3,head1->data);
		head1=head1->next;
	}
	while(head2!=NULL){
		insert_at_tail(head3,head2->data);
		head2=head2->next;
	}
	return head3;
}

int main(){

	node* head1 = NULL;
	make_new_user_list(head1);
	node* head2 = NULL;
	make_new_user_list(head2);

	node* head3=merge(head1,head2);
	print(head3);


	return 0;
}