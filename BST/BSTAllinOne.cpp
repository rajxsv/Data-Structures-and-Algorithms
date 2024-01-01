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
	int d;
	cin>>d;

	while(d!=-1){
		insertNode(root,d);
		cin>>d;
	}
	return root;
}

node* deleteInBST(node* &root,int val){
	if(root==NULL){
		return NULL;
	}
	if(val<root->data){
		root->left = deleteInBST(root->left,val);
		return root;
	}
	else if(val==root->data){
			// we have 3 cases
		// 1. node with no children

		if(root->left==NULL and root->right==NULL){
			delete root;
			return NULL;
		}

		// 2. node with 1 child
		   // either it has only right child or left child
		if(root->right!=NULL && root->left==NULL){
			node* temp = root->right;
			delete root;
			return temp;
		}
		if(root->right==NULL && root->left!=NULL){
			node* temp = root->left;
			delete root;
			return temp;
		}
		// 3. node with 2 children
		// now we can replace the node with the "next inorder succession" of that root
		// so first we find that
		// that element WHICH is the left most element to the 'right' node of that node we are deleting
		// so,
		node* replace = root->right;

		while(replace->left!=NULL){
			replace = replace->left;
		}
		// now we copy the data of this element to the root
		root->data = replace->data;
		// now its time to delete that node that we copied earlier 'replace node'
		// as now its present 2 times
		root->right = deleteInBST(root->right,replace->data);
		return root;	

	}
	else{
		root->right = deleteInBST(root->right,val);
		return root;
	}

} 

bool BST_Check(node* &root,int minV = INT_MIN,int maxV = INT_MAX){
	if(root==NULL){
		return true;
	}
	if(root->data < maxV && root->data >= minV && BST_Check(root->left,minV,root->data) && BST_Check(root->right,root->data,maxV)){
		return true;
	}
	return false;
}

// Just a set of pointers
class linkedList{
public:
	node* head;
	node* tail;
};

linkedList flattenBST(node* root){
	linkedList l;

	if(root==NULL){
		l.head=l.tail=NULL;
		return l;
	}
	// for leaf node
	if(root->right==NULL && root->left==NULL){
		l.head=l.tail=root;
		return l;
	}

	// left is not null
	if(root->right==NULL && root->left!=NULL){
		linkedList leftll = flattenBST(root->left);
		leftll.tail->right=root;

		l.head = leftll.head;
		l.tail = root;
		return l; 
	}
	// right is not null
	if(root->right!=NULL && root->left == NULL){
		linkedList rightll = flattenBST(root->right);
		root->right = rightll.head;

		l.head = root;
		l.tail = rightll.tail;
		return l;
	}
	// both are not NULL
	linkedList leftll = flattenBST(root->left);
	linkedList rightll = flattenBST(root->right);

	leftll.tail->right = root;
	root->right = rightll.head;

	l.head = leftll.head;
	l.tail = rightll.tail;

	return l;

}


int main(){

	node* root = BuildBST();
	BFS(root);

	// deleteInBST(root,5);
	BFS(root);

	if(BST_Check(root)){
		cout<<"It is BST"<<endl;
	}
	else{
		cout<<"Not BST"<<endl;
	}

	linkedList l = flattenBST(root);
	node* linkedlist = l.head;

	while(linkedlist!=NULL){
		cout<<linkedlist->data<<"--->";
		linkedlist=linkedlist->right;
	}
	cout<<"END\n";
	return 0;
}