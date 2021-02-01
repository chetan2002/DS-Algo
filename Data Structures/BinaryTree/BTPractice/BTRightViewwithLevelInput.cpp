#include<bits/stdc++.h>
using namespace std;

class node{
    public: 
        int data ;
        node* left;
        node* right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

//RECURSIVE BUILDING TREE IN PREORDER
//it inputs the each value and 
//if it is -1 attaches a null to the respective node 
//otherwise it does preorder building of tree
node* buildTreeLevel(){
    node* root = nullptr;
    int data ;
    cin>>data;
    if(data == -1){
        return nullptr;
    }

    root = new node(data);
    queue<node*> q;
	q.push(root);
    while(!q.empty()){
        node* x = q.front();
        q.pop();

        int left_data , right_data;
        cin>>left_data>>right_data;
        if(left_data != -1){
            x->left = new node(left_data);
			q.push(x->left);
        }
        if(right_data != -1){
            x->right = new node(right_data);
            q.push(x->right);
        }
    }
    return root;
}


//printing the right view
void RightView(node* root , int curr , int &maxi){
    //base case
    if(root==nullptr){
        return;
    }

    //recursive
	// cout<<root->data<<" ";
    if(curr>maxi){
        cout<<root->data<<" ";
        maxi = curr;
    }
    RightView(root->right , curr+1 , maxi);
    RightView(root->left , curr+1 , maxi);
   
    
    return;
}
int main(){
	node* root = buildTreeLevel();
	int max= -1;
	RightView(root , 0 , max);
	return 0;
}
