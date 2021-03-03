//https://hack.codingblocks.com/app/contests/2022/8/problem

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		left = nullptr;
		right = nullptr;
	}
};

//Create Tree using Inorder and Preorder
int pre[1005];
int pos= 0;
int in[1005];

node* CreateTree(int s , int e){
    //base case
    if(s>e){
        return nullptr;
    }
    //recursive case
    int d=pre[pos++];
    node* root = new node(d);
    int k = -1;
    for(int j=s; j<=e ; j++){
        if(in[j] == d){
            k = j;
            break;
        }
    }

    root->left = CreateTree(s , k-1);
    root->right = CreateTree(k+1 , e);

    return root;
}

void preOrder(node* root){
	if(!root){
		return ;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}
class sol{
public:
	int size;
	int max;
	int min;
	int ans;
	bool bst;
};

sol sizeOfBST(node* root){
	if(root==nullptr){
		sol s1;
		s1.size = 0;
		s1.max = INT_MIN;
		s1.min = INT_MAX;
		s1.bst = true;
		s1.ans = 0;
		return s1;
	}
	if(root->left == nullptr and root->right == nullptr){
		sol s1;
		s1.size = 1;
		s1.max = root->data;
		s1.min = root->data;
		s1.bst = true;
		s1.ans = 1;
		return s1;
	}

	sol left = sizeOfBST(root->left);
	sol right = sizeOfBST(root->right);

	sol s1;
	s1.size = left.size + right.size +1;

	if(left.bst and right.bst and root->data>left.max and root->data<right.min){
		s1.ans = s1.size;
		s1.bst = true;
		s1.min = min(left.min , min(right.min , root->data));
		s1.max = max(right.max , max(left.max , root->data));
		return s1;
	}

	s1.ans = max(left.ans , right.ans);
	s1.bst = false;
	return s1;

}

int main(){
	ll n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>pre[i];
	}
	for(int i=0;i<n;i++){
		cin>>in[i];
	}

	node* root= CreateTree(0 , n-1);

	sol s1 = sizeOfBST(root);

	cout<<s1.ans<<endl;
	

	return 0;
}