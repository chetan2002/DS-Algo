//https://hack.codingblocks.com/app/contests/2022/416/problem
#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left ;
	node* right;

	node(int d){
		data = d;
		node->right = nullptr;
		node->left = nullptr;
	}
};

node* buildPre(string s){
	
	if(s=="true"){	
		int d;
		cin>>d;
		node* root = new node(d);
		string l;
		cin>>l;
		
			root->left = buildPre(l);
		
		string r ;
		cin>>r;
		
			root->right = buildPre(r);
		
		return root;
	}
	return nullptr;
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

int main(){
	node* root=nullptr;
	root = buildPre("true");
	int val1 ;
	cin>>val1;
	int val2;
	cin>>val2;
	
	node* found = lca(root , val1 , val2);
	cout<<found->data<<endl;

	return 0;
}