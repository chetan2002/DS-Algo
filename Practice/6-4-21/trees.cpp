#include<iostream>
using namespace std;

class node{
public: 
    int data;
    node* left;
    node* right;
    node(int d):data(d) , left(nullptr) , right(nullptr){};
};

node* buildTree(){
    int data;
    cin>>data;
    if(data == -1){
        return nullptr;
    }else{
        node* root = new node(data);
        root->left = buildTree();
        root->right = buildTree();
        return root;
    }
}
int count(node* root){
    if(root==nullptr){
        return 0;
    }
    return 1+count(root->left)+count(root->right);
}

int height(node* root){
    if(root==nullptr){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return max(left , right)+1;
}

node* buildTreeLevel(){
    node* root = nullptr;
    int data;
    cin>>data;
    if(data == -1){
        return nullptr;
    }
    root = new node(data);
    queue<node> q;
    q.push(root);
    while(!q.emtpy()){
        node* x = q.front();
        q.pop();

        int left , right;
        cin>>left>>right;
        if(left!=-1){
            x->left = new node(left);
            q.push(x->left);
        }
        if(right!=-1){
            x->right = new node(right);
            q.push(x->right);
        }
    }
    return root;
}


int diameter(node* root){
    if(root==nullptr){
        return 0;
    }
    //if diameter passes through root
    //if diameter lies in left part
    //if diameter lies in right part
    int op1 =1+ height(root->left)+height(root->right);
    int op2 = diameter(root->right);
    int op3 = diameter(root->left);
    return max(op1 , max(op2 , op3));
}

class pair{
public:
    int height ;
    int diameter;
    pair(int h , int d){
        height = h;
        diameter = d;
    }
};

pair diam(node* root){
    if(root==nullptr){
        pair p(0 ,0);
        return p;
    }

    pair left = diam(root->left);
    pair right = diam(root->right);

    pair p;
    p.height = max(left.height , right.height)+1;
    int op1 = 1+ left.height + right.height;
    int op2 = left.diameter;
    int op3 = right.diameter;

    return max(op1 , max(op2 , op3));
}


int main(){

    return 0;
}