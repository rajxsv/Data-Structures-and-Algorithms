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
void insert_at_head(node* &head , int d){
    if(head==NULL){
        head=new node(d);
        return;
    }

    node* new_node = new node(d);
    new_node->next=head;
    head=new_node;
}
void print(node* head){

    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
    return;
}
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
void insert_at_pos(node* &head,int pos,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }
    node* temp=head;
    int node_no=1;
    while(node_no!=(pos-1)){
        temp = temp->next;
        node_no++;
    }
    node* n =new node(d);
    n->next=temp->next;
    temp->next=n;
    return;
}
void delete_at_pos(node* &head,int pos){
    if(head==NULL){
        return;
    }
    node* temp=head;
    int node_no=1;
   
    while(node_no!=(pos-1)){
        temp=temp->next;
        node_no++;
    }
   
    node* n = temp->next->next;
    delete temp->next;
    temp->next=n;
}
void operator<<(ostream &cout,node* &head){
    print(head);
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
int main(){
    node* head = NULL;
    
    insert_at_head(head,5);
    insert_at_head(head,4);
    insert_at_head(head,3);
    insert_at_head(head,2);
    insert_at_head(head,1);
    insert_at_head(head,0);
    print(head);
    
    
    insert_at_tail(head,6);
    print(head);

    insert_at_pos(head,5,100);
    print(head);

    delete_at_pos(head,5);
    print(head);

    // delete_at_pos(head,1);
    // // overloading the << operator
    // cout<<head;

    node* head2 = NULL;
    make_new_user_list(head2);
    print(head2);
    return 0;
}