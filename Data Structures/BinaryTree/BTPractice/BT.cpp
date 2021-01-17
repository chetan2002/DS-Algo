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
    if(d==-1){
        return NULL;
    }

    //create new node
    node* root = new node(d);

    //build left subtree
    root->left = buildTree();

    //build right subtree
    root->right = buildTree();

    //return root
    return root;

}

void printPreOrder(node* root){
    if(root == NULL){
        return ;
    }
    //otherwise , print the root first followed by subtrees(children)
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

//POST-ORDER TRAVERSAL
//if root is null , return
//otherwise , call the left and right subtree
//and then print the value of the current node
void printPostOrder(node* root){
    if(root == NULL){
        return;
    }
    //otherwise
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}

//IN-ORDER TRAVERSAL
//if root is null , return 
//first call the left subtree 
//print the current node
//and now call the right subtree
void printInOrder(node* root){
    if(root == NULL){
        return ;
    }

    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

//counting nodes of tree
int CountNodes(node* root){
    if(root==nullptr){
        return 0;
    }
    return CountNodes(root->left) + CountNodes(root->right) + 1;
}

//height of tree
int height(node* root){
    if(root==nullptr){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return 1+max(left,right);
}

int Diameter(node* root){
    if(root == nullptr){
        return 0 ;
    }
    int op1 = height(root->left)+height(root->right);
    int op2 = Diameter(root->left);
    int op3 = Diameter(root->right);
    return max(op1 , max(op2 , op3));
}

int main(){
    node* root;
    root = buildTree();
    cout<<CountNodes(root)<<endl;
    cout<<height(root)<<endl;

    return 0;
}