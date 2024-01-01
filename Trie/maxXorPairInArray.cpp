#include<iostream>
using namespace std;

class Node{
public:
    Node* left;  //for 0
    Node* right;   // for 1
};

class Trie{
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    //lets insert an integer
    void insert(int n){
        
        Node* temp = root;
        
        for(int i=31;i>=0;i--){
        
            int bit = (n>>i)&1;
        
            if(bit==0){
                if(temp->left == NULL){
                    temp->left = new Node();
                }
                temp=temp->left;
            }else{
                if(temp->right == NULL){
                    temp->right = new Node();
                }
                temp = temp->right;
            }
        }
    }

    // ! now to find maxXor in this trie

    int maxXorHelper(int value){
        //we send one by one and check it with already present elements
        int currAns = 0;
        Node* temp = root;

        for(int j=31;j>=0;j--){
            int bit = (value>>j)&1;

            if(bit==0){
                if(temp->right!=NULL){
                    temp = temp->right;
                    currAns += (1<<j);   //2to power j
                }
                else{
                    temp=temp->left; //0 does not contribue
                }
            }
            else{
                //bit is 1
                if(temp->left!=NULL){
                    temp=temp->left;
                    currAns += (1<<j);
                }
                else{
                    temp=temp->right;
                }
            }
        }
        return currAns;                  
    }

    int maxXor(int *input,int n){
        int maxXor = 0;
        for(int i=0;i<n;i++){
            int val = input[i]; 
            
            insert(val);
            int currXor = maxXorHelper(val);
            
            // cout<<currXor<<" ";

            maxXor = max(currXor,maxXor);
        }
        return maxXor;
    }
};

int main(){

    int input[] = {3,10,5,25,2,8};
    Trie t;
    cout<<t.maxXor(input,6);

    return 0;
}