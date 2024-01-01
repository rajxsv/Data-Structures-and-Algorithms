#include <iostream>
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

int replaceSum(root* T){
	if(T==NULL){
		return 0;
	}

	if(T->left == NULL && T->right==NULL){
		return T->data;
	}

	int leftSum = replaceSum(T->left);
	int rightSum = replaceSum(T->right);   //both these will be recieved well by the return statement at the end 

	int temp = T->data;
	T->data = leftSum + rightSum;

	return temp + T->data;  //this basically being the required sum for parent 6
}
void BFS(root* &T){
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
int main(){

	root* T = NULL;
	T = input_preorder();
	BFS(T);

	replaceSum(T);

	BFS(T);
	return 0;
}