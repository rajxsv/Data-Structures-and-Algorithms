#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;
// ! Checking if a word is present in list of strings
// We can think of hashing , brute force pr 
// ! Prefix Tree -> Trie!


//almost all queries here take O(1) time
class Node{
    public:
    char data;
    unordered_map<char,Node*> children;
    bool terminal;
    
    Node(char d){
        data=d;
        terminal=false; //initially false
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node('\0');
    }

    void insert(char *w){

        Node* temp = root;
        
        for(int i=0;w[i]!='\0';i++){
            char ch = w[i];
            if(temp->children.count(ch)){
                //go to that node which is stored in the hashmap (second pair element)
                temp=temp->children[ch];
                // dont worry next character will automatically be read because of for loop
            }
            else{
                Node* n = new Node(ch);
                temp->children[ch]=n;
                temp=n;
            }
        }
        temp->terminal=true;
    }
    bool find(char *w){
        Node* temp = root;
        for(int i=0;w[i]!='\0';i++){
            char ch = w[i];
            if(temp->children.count(ch)==0){
                return false;
            }
            else{
                temp=temp->children[ch];
            }
        }
        return temp->terminal;
    }
};

int main(){

    Trie t;
    char words[][10] = {"a","hello","net","news","apple"};
    char w[10];
    cin>>w;
    for(int i=0;i<5;i++){
        t.insert(words[i]);
    }

    if(t.find(w)){
        cout<<"present"<<endl;
    }
    else{
        cout<<"Not Present"<<endl;
    }
    return 0;
}