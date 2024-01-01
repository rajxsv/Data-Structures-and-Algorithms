#include<iostream>
#include <queue>
using namespace std;

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


void levelOrderBFS1(root* &T){
	queue <root*> q;
	q.push(T);

	while(!q.empty()){
		root* n = q.front();
		q.pop();

		cout<<n->data<<" ";

		if(n->left){
			q.push(n->left);
		}
		if(n->right){
			q.push(n->right);
		}
	}
	return;
}

void levelOrderBFS2(root* &T){
	queue <root*> q;
	q.push(T);
	q.push(NULL);

	while(!q.empty()){
		root* n = q.front();
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

int countAllElements(root* T){

	if(T==NULL)return 0;

	return 1+countAllElements(T->left) + countAllElements(T->right);  
}
int sumAllElements(root* T){

	if(T==NULL)return 0;

	return (T->data) + sumAllElements(T->left) + sumAllElements(T->right);  
}
int diameterTree(root* T){
	int hl = heightTree(T->left);
	int hr = heightTree(T->right);

	int a = hl + hr;
	int b = diameterTree(T->left);
	int c = diameterTree(T->right);


	return max(a,max(b,c));

}	
int main(){

	// we can optimise the level traversal by using the bfs algo
 	// which uses the queue data structure 
 	// when the queue is not empty we just simply print the first 
 	// data in front  of the queue and then we push the children of 
 	// that particular data into the queue
 	// this approach is O(N) as compared to earlier one
 	// which was O(N^2)

 	root* T = NULL;
 	T = input_preorder();

 	levelOrderBFS1(T);

 	cout<<"\nNow with endline char after every level"<<endl;
 	levelOrderBFS2(T);

 	cout<<sumAllElements(T)<<endl;
 	cout<<countAllElements(T)<<endl;

 	cout<<diameterTree(T)<<endl;















































	return 0;
}
