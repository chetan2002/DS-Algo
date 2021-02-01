#include<iostream>
using namespace std;

class node{
public:
	int val;
	node* left;
	node* right;

	node(int v){
		val = v;
		left = nullptr;
		right = nullptr;
	}
};

node* createTree(int *post , int *ino , int s , int e , int &j){
	if(s>e){
		return nullptr;
	}
	if(j<0){
		return nullptr;
	}

	int d = post[j--];
	node* root = new node(d);
	int k = -1;
	for(int i=s ; i<=e ; i++){
		if(ino[i] == d){
			k=i;
		}
	}

	root->right = createTree(post , ino , k+1 , e , j);
	root->left = createTree(post , ino , s , k-1 , j);

	return root;

}

void display(node* root){
	if(root==nullptr){
		return;
	}

	if(root->left!=nullptr){
		cout<<root->left->val<<" ";
	}else{
		cout<<"END ";
	}
	cout<<"=> "<<root->val<<" ";
	if(root->right != nullptr){
		cout<<"<= "<<root->right->val;
	}else{
		cout<<"<= END";
	}
	cout<<endl;

	display(root->left);
	display(root->right);
}
int main(){
	int n;
	cin>>n;
	int post[n];
	for(int i=0; i<n ; i++){
		cin>>post[i];
	}
	cin>>n;
	int ino[n];
	for(int i=0; i<n; i++){
		cin>>ino[i];
	}
	int j = n-1;
	node* root = createTree(post , ino , 0 , n-1 , j);

	display(root);

	return 0 ; 
}
