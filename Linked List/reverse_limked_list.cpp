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
void insert_at_tail(node* &head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }  
    node* new_node = new node(d);
    temp->next=new_node;
    return;
} 

void print(node* head){

    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
    return;
}
void make_new_user_list(node* &head){
    int n;
    cin >> n;
    
    if(n==0){
        return;
    }
    
    int data;
    for(int i=0;i<n;i++){
        cin >> data;
        insert_at_tail(head,data);
    }
    return;
}
void reverse_list(node* &head){
	if(head==NULL || head->next==NULL){
		return;
	}						
	node* curr = head;
	node* prev = NULL;

	while(curr!=NULL){
		node* n = curr->next;
		
		// make the left to the left side in every iteration
		curr->next=prev;

		prev=curr;
		curr=n;
	}
	head=prev;
															1->next->2->NULL
}
															sH = 3->2->NULL



node* rec_reverse1(node* &head){

	if(head==NULL || head->next==NULL){
		return head;
	}													
	node* small_head = rec_reverse1(head->next);

	head->next->next=head;
	head->next=NULL;
	return small_head;
}
node* rec_reverse2(node* head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	node* small_head = rec_reverse2(head->next);

	node* temp = small_head;
	while(temp->next !=NULL){
		temp=temp->next;
	}
	temp->next=head;
	head->next=NULL;
	
	return small_head;
}
int main(){
	
	node* head=NULL;
	make_new_user_list(head);
	print(head);
	reverse_list(head);
	print(head);
	head=rec_reverse1(head);					
	print(head);
	head=rec_reverse2(head);					
	print(head);
	return 0;
}