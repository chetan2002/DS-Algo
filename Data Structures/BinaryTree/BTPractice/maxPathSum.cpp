//https://hack.codingblocks.com/app/contests/2022/1339/problem
#include <bits/stdc++.h>
using namespace std;

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

node* buildTree(){
    string s;
    cin>>s;
    if(s=="NULL"){
        return nullptr;
    }

    node* root = new node(stoi(s));
    root->left =buildTree();
    root->right = buildTree();
    return root;
}

void preorder(node* root){
    if(root==nullptr){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int maximumSumPath(node* root , int &maxi){
    if(root==nullptr){
        return 0;
    }
    int left = maximumSumPath(root->left  , maxi);
    int right = maximumSumPath(root->right , maxi);

    int value = max(root->data , left+right+root->data);
    value = max(value , left+root->data);
    value = max(value , right+root->data);

    maxi = max(value , maxi);

    return max(root->data , max(left , right)+root->data);
}


int main() {
    /* code here */
    node* root = nullptr;
    root= buildTree();

    int maxi = 0;
    maximumSumPath(root , maxi);
    cout<<maxi<<endl;
    // preorder(root);
    return 0;
}