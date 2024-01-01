#include <iostream>
using namespace std;

// dia of a tree is the longest path that you can take 
	// from one node to another
	// there can be 3 options either all nodes lie that make the diameter
	// on left side,
	//they are included with the root node stretching from one side to another 
	// the last case is that it lies completely on right side
// IT IS INTERESTING TO NOTE THAT THE DIMETER IS COMPOSED OF THE PATH (LINES) RATHER THAN 
// THE NODES ITSELF
// **SO FOR the lowest LEVEL NODE WE CAN SAY THE DIA FOR ONE SIDE IS BASICALLY THE HEIGHT OF ONE SIDE+SIDE TWO

class Pair{

public:
	int height;
	int diameter;

};

class root{
public:
	int data;
	root* left;
	root* right;

	root(int d){
		data = d;
		left=NULL;
		right=NULL;
	}
};

root* input_preorder(){
	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}

	root* T = new root(d);

	T->left = input_preorder();
	T->right = input_preorder();

	return T;
}

int heightTree(root* T){
	if(T==NULL){
		return 0;
	}

	int ls = heightTree(T->left);
	int rs = heightTree(T->right);

	return max(ls,rs) + 1;
}	

int diameterTree(root* T){
	if(T==NULL)return 0;

	int hl = heightTree(T->left);
	int hr = heightTree(T->right);

	int a = hl + hr + 1;   ///+ 1 for the current node
	
	int b = diameterTree(T->left);
	int c = diameterTree(T->right);


	return max(a,max(b,c));

}	

Pair efficientDiameterTree(root* T){
	Pair p;
	if(T==NULL){
		p.height=p.diameter=0;
		return p;
	  //return make_pair(0,0);
	}


	Pair left = efficientDiameterTree(T->left);
	Pair right = efficientDiameterTree(T->right);

	//   here ww calculate the height while constantly going through the stacks
	p.height = max(left.height,right.height)+1;

	// this stays same
	p.diameter = max(left.height+right.height,max(left.diameter,right.diameter));

	return p;

}

int main(){

	root* T = NULL;
	T = input_preorder();

	cout<<diameterTree(T)<<endl;

	cout<<efficientDiameterTree(T).diameter<<endl;
	cout<<efficientDiameterTree(T).height<<endl;

	return 0;
}