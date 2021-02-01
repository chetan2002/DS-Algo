//https://hack.codingblocks.com/app/contests/2022/1085/problem
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* right;
    node* left;

    node(int d){
        data = d;
        right  = nullptr;
        left = nullptr;
    }
};

node* buildTree(){

    //input data
    int d;
    cin>>d;

    //if data is -1 , attach as null

    //create new node
    node* root = new node(d);
	int child = 0;
	cin>>child;

    //build left subtree
	if(child==0){
		return root;
	}else{
		
		 root->left = buildTree();

		if(child==1){
			return root;
		}
    	//build right subtree
    	root->right = buildTree();
	}
   

    //return root
    return root;

}
void printPreOrder(node* root ,int k , int lev ,int& sum){
    if(root == NULL){
        return ;
    }
    //otherwise , print the root first followed by subtrees(children)
    if(lev == k){
		sum+=root->data;
	}
    printPreOrder(root->left , k , lev+1 , sum);
    printPreOrder(root->right , k , lev+1 , sum);
}
int main() {
	node* root = buildTree();
	int k=0;
	cin>>k;
	int sum=0;
	printPreOrder(root , k ,0 , sum);
	cout<<sum<<endl;
	return 0;
}