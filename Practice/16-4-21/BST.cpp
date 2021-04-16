#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right ;
    node(int d):data(d) , left(NULL) ,right(NULL){}
};

void preOrder(node* root){
    if(root == nullptr){
        return ;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){

    return 0;
}