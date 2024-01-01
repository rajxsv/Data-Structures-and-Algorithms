// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
public:
    Node* next;    
    Node* prev;
    int val;
    
    Node(int val){
        this->val = val;
        
        next = NULL;
        prev = NULL;
    }
};

int main() {
    // Write C++ code here
    int data;
    cin >> data;
    
    Node* head = NULL;
    Node* tail = NULL;
    Node* p = head;
    
    while(data != -1){
        if(head == NULL){
            head = new Node(data);
            head->next = tail;
            
            p = head;
            continue;
        }
        
        tail = new Node(data);
        
        tail->prev = p;
        p->next = tail;
        
        p = tail;
        tail = tail->next;
        
        cin >> data;
    }
    
    
    while(head != tail){
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}