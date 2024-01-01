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
        head = head->next;
    }
    cout<<"NULL"<<endl;
    return;
}
int kthnode(node* head){
	int k;
	cin>>k;

	node* slow=head;
	node* fast=head;
	for(int i=0;i<k;i++){
		fast=fast->next;
	}
	while(fast!=NULL){
		fast=fast->next;
		slow=slow->next;
	}
	return slow->data;
}
int main(){
	node* head=NULL;
	takeinput(head);
	print(head);
	cout<<kthnode(head);
}