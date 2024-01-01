#include <iostream>
#include <queue>
using namespace std;

/*
	1:
	In a height balanced tree the difference of height of tree 
	on left hand side and right hand side is less than equal to 1

				|h1-h2| <= 1 

	we use a postorder recursive approach to solve this question

	2:
	in the second part we make a height balanced tree from an array
	the approach being that we find  the mid of array assign is to the node and recursively 
	call for other elements in array as (s,mid-1) and (mi+1,e);
*/

class node{

public:
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		left = NULL;
		right=NULL;
	}

};

node* input(){

	int c;
	cin>>c;

	if(c==-1){
		return NULL;
	}

	node* root = new node(c);

	root->left = input();
	root->right = input();

	return root;
}

class HBPair{
public:
	int height;
	bool balance;
};

HBPair checkBalance(node* root){
	HBPair p;
	// base case , leaf node is always balanced
	if(root==NULL){
		p.height=0;
		p.balance=true;

		return p;
	}

	HBPair left = checkBalance(root->left);
	HBPair right = checkBalance(root->right);

	p.height = max(left.height,right.height) + 1;

	if(abs(left.height-right.height)<=1 and left.balance && right.balance){
		p.balance = true;
	}
	else{
		p.balance = false;  
	}
	return p;	
}

node* makeTreeFromArray(int* arr,int start,int end){
	if(start>end){
		return NULL;
	}

	int mid = (start+end)/2;

	node* root = new node(arr[mid]);

	root->left = makeTreeFromArray(arr,start,mid-1);
	root->right = makeTreeFromArray(arr,mid+1,end);

	return root;
}

void BFS(node* &T){
	queue <node*> q;
	q.push(T);
	q.push(NULL);

	while(!q.empty()){
		node* n = q.front();
		q.pop();

		if(n == NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<n->data<<" ";	

			if(n->left){
				q.push(n->left);
			}
			if(n->right){
				q.push(n->right);
			}
		}
	}
	return;
}

int main(){

	node* root = input();

	if(checkBalance(root).balance){
		cout<<"Balanced"<<endl;
	}
	else{
		cout<<"Not Balanced"<<endl;
	}

	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(arr)/sizeof(arr[0]);

	node* root2 = makeTreeFromArray(arr,0,n-1);
	BFS(root2);
	return 0;
}