//https://hack.codingblocks.com/app/contests/2022/78/problem
#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right ;

	node(int d){
		data = d;
		left = nullptr;
		right = nullptr;
	}

};

node* buildTree(){
	int d;
	cin>>d;
	queue<node*> q;
	node* root = new node(d);
	if(d!=-1){
		q.push(root);
	}
	while(!q.empty()){
		node* top = q.front();
		q.pop();

		if(top!=nullptr){
			int left , right ;
			cin>>left>>right;

			if(left!=-1){
				node* l = new node(left);
				top->left = l;
				q.push(l);
			}

			if(right!=-1){
				node* r = new node(right);
				top->right = r;
				q.push(r);
			}
		}
	}
	return root;
}

map<int , vector<node*>> mp;
void preorder(node* root , int pos){
	if(root==nullptr){
		return ;
	}

	mp[pos].push_back(root);
	
	preorder(root->left , pos-1);
	preorder(root->right , pos+1);
}

void verticalPrint(node* root){
	if(root==nullptr){
		return;
	}
	preorder(root , 0);
	for(auto c: mp){
		for(auto a: c.second){
			cout<<a->data<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int levels;
	cin>>levels;
	node* root ;
	root = buildTree();

	verticalPrint(root);
	// preorder(root);
	return 0;
}