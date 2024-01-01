#include <iostream>
#include <queue>
using namespace std;
/*
    Pick an element from Preorder. Increment a Preorder Index Variable to pick the next element in the next recursive call. 
    Create a new tree node tNode with the data as the picked element. 
    Find the picked element’s index in Inorder. Let the index be inIndex. 
    Call buildTree for elements before inIndex and make the built tree as a left subtree of tNode. 
    Call buildTree for elements after inIndex and make the built tree as a right subtree of tNode. 
    return tNode.
*/

class node{
public:
    int data;
    node* left;
    node* right;


    node(int d){	
    	data = d;
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

node* buildTreePreIn(int* pre,int* in, int s, int e){
	static int i = 0; //this is basically for the iteration in pre array

	// base case
	if(s>e){
		return NULL;
	} 

	// rec case
	node* root = new node(pre[i]);

	int index = -1;   //this is for finding the same element in 
						// the inorder array as we want to break the array from there  
	for(int j=s;j<=e;j++){
		if(in[j]==pre[i]){
			index=j;
			break;
		}
	}
	
	i++;//getting ready for nexr element picking in pre array in next call

	// since the element  at 'index' is already alloted we call for remaining 2 left divisions of array
	root->left = buildTreePreIn(pre,in,s,index-1);
	root->right = buildTreePreIn(pre,in,index+1,e);

	return root;
}

int main(){
	int pre[] = {3,9,20,15,7};
	int in[] = {9,3,15,20,7};

	int n = sizeof(pre)/sizeof(pre[0]);
	// node* root = input();
	// BFS(root);
	
	node* root = buildTreePreIn(pre,in,0,n-1);
	BFS(root);

	return 0;
}