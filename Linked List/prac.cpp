#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node*next;
    //constructor 
    node(int d){
        data=d;
        next=NULL;
    }
};
void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
void insertAtTail(node*&head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }
    node*tail=head;
    while(tail->next != NULL){
        tail=tail->next;
    }
    tail->next =new node(d);
    return;
}
node*take_input(int n){
    
    node*head=NULL;
    for(int i=0;i<n;i++){
        int no;
        cin>>no;
        insertAtTail(head,no);
    }
    return head;
} 
void kAppend(node*head,int k,int n){
    node*prev=head;
    node*curr=head->next;
    int i=0;
    while(i < n-k-1 ){
        prev=prev->next;
        curr=curr->next;
        i++;
    }
    prev->next=NULL;
    node*temp = curr;
    while(temp->next != NULL){
        temp= temp->next;
    }
    temp->next=head;
    print(curr);
}
int main()
{
    int n;
    cin>>n;
    node*head=take_input(n);
    int k;
    cin>>k;
    // print(head);
    // cout<<endl;
    if(k<n){
		kAppend(head,k,n);
	}
    else if(k==n){
		print(head);
	}
    else {
		kAppend(head,k%n ,n);
	}
    return 0;
}