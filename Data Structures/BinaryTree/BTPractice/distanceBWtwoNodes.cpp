//https://hack.codingblocks.com/app/contests/2022/1881/problem
#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left ;
	node* right;

	node(int d){
		data = d;
		right = nullptr;
		left = nullptr;
	}
};

node* buildPre(){
	
	
	int d;
	cin>>d;
	if(d!=-1){
		node* root = new node(d);

		root->left = buildPre();
		root->right = buildPre();
		return root;
	}else{
		return nullptr;
	}
	
}

void preOrder(node* root){
	if(root==nullptr){
		//cout<<"watThefuck"<<" ";
		return;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

node* lca(node* root , int val1 , int val2){
	if(root==nullptr){
		return root;
	}
	if(root->data==val1 || root->data==val2){
		return root;
	}
	node* left = lca(root->left , val1 , val2);
	node* right = lca(root->right , val1 , val2);

	if(left!=nullptr and right!=nullptr){
		return root;
	}
	if(left==nullptr and right == nullptr){
		return nullptr;
	}
	return (left!=nullptr)?left:right;
}

int level(node* root , int a , int l){
	if(root == nullptr){
		return -1;
	}
	if(root->data == a){
		return l;
	}
	int left = level(root->left , a , l+1);
	if(left == -1){
		return level(root->right , a , l+1);
	}
	return left;
}


int answer(node* root , int a , int b){
	node* ances = lca(root , a , b);

	int d1 = level(ances , a , 0);
	int d2 = level(ances , b , 0);

	return d1+d2;
}

int main(){
	node* root=nullptr;
	root = buildPre();
	
	// preOrder(root);
	// cout<<endl;
	int t;
	cin>>t;
	while(t--){
		int a, b ;
		cin>>a>>b;
		cout<<answer(root , a , b)<<endl;
	}

	return 0;
}