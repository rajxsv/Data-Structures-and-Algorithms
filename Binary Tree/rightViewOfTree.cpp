#include <iostream>
#include <queue>

using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data= d;
		left = NULL;
		right = NULL;

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
void BFSrightView(node* root){

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* n = q.front();
		q.pop();

		if(n==NULL){
			cout<<endl;
			
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			if(q.front()==NULL){
				cout<<n->data<<" ";
			}

			if(n->left){
				q.push(n->left);
			}
			if(n->right){
				q.push(n->right);
			}
		}

	}

}

void rightView(node* root,int level ,int &maxLevel){
	if(root==NULL){
		return;
	}

	if(level>maxLevel){

		cout<<root->data<<" ";
		maxLevel=level;
	}

	// call right
	// call left

	rightView(root->right,level+1,maxLevel);
	rightView(root->left,level+1,maxLevel);

	return;
}

int main(){


	node* root = input();
	BFSrightView(root);
	int maxLevel = -1;
	 
	rightView(root,0,maxLevel);
	return 0;
}