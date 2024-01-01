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

void BFS(node* &root){
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
			cout<<n->data<<" ";

			if(n->left){
				q.push(n->left);
			}
			if(n->right){
				q.push(n->right);
			}
		}

	}

}

void insertNode(node* &root,int d){
	if(root==NULL){
		root = new node(d);
		return;
	}

	if(d>root->data){
		insertNode(root->right,d);
	}
	else{
		insertNode(root->left,d);
	}

	return;
}

node* BuildBST(){
	node* root=NULL;
	int d;cin>>d;

	while(d!=-1){
		insertNode(root,d);
		cin>>d;
	}
	return root;
}

int main(){

	node* root = BuildBST();
	BFS(root);
	
	return 0;
}