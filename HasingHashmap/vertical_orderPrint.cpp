#include <iostream>
#include <map>
#include <vector>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int data){
		this->data = data;
		left=right=NULL;
	}
};
//always pass mao with reference
void verticalOrderPrint(node* root,int d,map<int,vector<int>> &m){
	if(root==NULL){
		return;
	}

	//rec case`
	m[d].push_back(root->data);
	verticalOrderPrint(root->left,d-1,m);  //go left d cec by 1
	verticalOrderPrint(root->right,d+1,m);  //go right d inc by 1
	return;
}

int main(){

	node* root = new node(1);

	root->left = new node(2);
	root->right = new node(3);

	root->left->left = new node(4);
	root->left->right = new node(5);

	root->right->left = new node(6);
	root->right->right = new node(7);

	root->right->right->right = new node(9);

	root->left->right->right = new node(8);	

	//IMAGINE THIS TREE AND THEN WE WANT TO PRINT IT INT VERTICAL ORDER 
	
	map <int,vector<int>> m;
	// int distance = 0;
	verticalOrderPrint(root,0,m);

	//now keys are sorted already!

	for(auto p:m){
		cout<<p.first<<" ->";
		for(auto x:p.second){
			cout<<x<<",";
		}
		cout<<endl;
	}

	return 0;

}

