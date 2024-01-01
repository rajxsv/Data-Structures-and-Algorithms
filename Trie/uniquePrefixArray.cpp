#include<iostream>
#include<unordered_map>
using namespace std;
//tries is c/a prefix tree so prefix arrays can be solved using trie

class Node{
    public:
    char data;
    unordered_map<char,Node*> children;
    bool terminal;
    int freq = 0;

    Node(char d){
        data=d;
        terminal=false; //initially false
        freq = 1;
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
                temp->freq++;
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

    string preFix(char* w){
        Node* temp = root;
        string ans = "";

        for(int i=0;w[i]!='\0';i++){
            char ch = w[i];
            if(temp->children.count(ch)){
                temp=temp->children[ch];
                ans+=ch;
                // cout<<temp->freq<<endl;
                if(temp->freq == 1 && !temp->terminal){
                    return ans;
                }
            }
        }
        return ans;
    }
};


int main(){

    char words[][10] = {"zebra","dog","duck","dove"};
    Trie t;
    int n = 4;
    for(int i=0;i<4;i++){
        t.insert(words[i]);
    }

    for(int i=0;i<4;i++){
        cout<<t.preFix(words[i])<<endl;
    }
    
    return 0;
}