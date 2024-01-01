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

void printPreOrder(tree* T){
	if(T==NULL){
		return;
	}
	cout<<T->data<<" ";

	printPreOrder(T->left);
	printPreOrder(T->right);

}

void printPostOrder(tree* T){
	if(T==NULL){
		return;
	}

	printPostOrder(T->left);
	printPostOrder(T->right);
	cout<<T->data<<" ";
}

void printInOrder(tree* T){
	if(T==NULL){
		return;
	}

	printInOrder(T->left);
	cout<<T->data<<" ";
	printInOrder(T->right);
}

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

int heightTree(tree* T){
	if(T==NULL){
		return 0;
	}

	int ls = heightTree(T->left);
	int rs = heightTree(T->right);

	return max(ls,rs) + 1;

	// /this really helps in solving many problems

}
int main(){
	
	tree* T = NULL;
	T=input_preorder();
 
	cout<<"Pre-Order"<<endl;
	printPreOrder(T);
	
	cout<<endl<<"In-Order"<<endl;
	printInOrder(T);

	cout<<endl<<"Post-Order"<<endl;
	printPostOrder(T);
	
	return 0;
}