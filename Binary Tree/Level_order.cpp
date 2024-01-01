#include <iostream>
using namespace std;

class tree{

public:
	int data;
	tree* left;
	tree* right;

	// custom constructor
	tree(int dat){
		data = dat;
		left = NULL;
		right = NULL;
	}

};

tree* input_preorder(){
	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}

	tree* T=new tree(d);
	T->left = input_preorder();
	T->right = input_preorder();
	return T;
}

int heightTree(tree* &T){
	if(T==NULL){
		return 0;
	}
	int ls = heightTree(T->left);
	int rs = heightTree(T->right);

	return max(ls,rs)+1;
}

void printKLevel(tree* &T,int k){
	if(T==NULL){
		return;
	}

	if(k==1){
		cout<<T->data<<" ";
	}
	printKLevel(T->left,k-1);
	printKLevel(T->right,k-1);

	return;
}
void levelTraversal(tree* &T){
	int height = heightTree(T);

	for(int i=1;i<=height;i++){
		printKLevel(T,i);
		cout<<endl;
	}
}
int main(){

	tree* T = NULL;
	T=input_preorder();

	// for level traversal we first need to find height of tree
	// then we need to make a function for kth level
	// now we make a function to call the 
	// print k level function every time to print all level
	
	levelTraversal(T);
	return 0;
}