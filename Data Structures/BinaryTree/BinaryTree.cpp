//https://ide.codingblocks.com/s/383594
//Binary Tree Implementation

#include<bits/stdc++.h>
using namespace std;

//There are 4 types of traversal in a tree
//1. Preorder traversal
//2. Inorder traveral
//3. Postorder traversal
//4. Level Order Traversal

//NODE CLASS
//Creating the node class 
//members data , left and right and constructor
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

//PREORDER TRAVERSAL OF BINARY TREE
//print the tree in preorder
//take root as arguement 
//if root is null , return ;
//otherwise print the node and
//first iterate to left subtree
//then iterate to right subtree
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

//Find height of the tree
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);

    return max(ls , rs) +1;
}
//LEVEL-ORDER TRAVERSAL

//Print the kth level from start
void printKthLevel(node* root , int k){
    if(root == NULL){
        return ;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printKthLevel(root->left , k-1);
    printKthLevel(root->right , k-1);
}

//Print level order Naive approach
//run a loop from 1 to height of the tree 
//print all the levels by passing the value to printKthLevel
//complexity : O(N2)
void printAllLevel(node* root ){
    int h = height(root);

    for(int i=1;i<=h;i++){
        printKthLevel(root , i);
        cout<<endl;
    }
}

//Level Order Traversal 
//Breadth First Search -> O(n)

//this code prints all the nodes in level order with commas
void bfsWithoutNewLine(node *root){
    queue<node*> qu;
    qu.push(root);

    while(!qu.empty()){
        node* f = qu.front();
        cout<<f->data<<" , ";
        qu.pop();
        if(f->left){
            qu.push(f->left);
        }
        if(f->right){
            qu.push(f->right);
        }
    }
    return;
}

//this code prints bfs traversal and prints endl after every level
void bfsWithNewLine(node* root){
    queue<node*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        node* f = q.front();
        if(f==nullptr){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(nullptr);
            }
        }else{
            cout<<f->data<<" ";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
}

//to count the nodes of the tree
int count(node* root){
    if(root==nullptr){
        return 0;
    }
    return 1+ count(root->left) + count(root->right);
}

//to find the sum of nodes of the tree
int SumOfAllNodes(node* root){
    if(root==nullptr){
        return 0;
    }
    return root->data + SumOfAllNodes(root->left) + SumOfAllNodes(root->right);
}

//Diameter of the tree
//Diameter of a tree is the longest distance between any two nodes
//there can be three cases for the diameter of tree
//1. Diameter passes through root -> height(left)+height(right) will give us diameter
//2. Diameter is in left subtree -> call diameter in left part and rest recursion will handle
//3. Diameter is in right subtree -> call diameter in right part and rest recursion will handle
int diameterOfTree(node* root){           
    if(root==nullptr){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int PassThroughRoot = h1+h2;
    int inLeftSide = diameterOfTree(root->left);
    int inRightSide = diameterOfTree(root->right);

    return max(PassThroughRoot , max(inLeftSide , inRightSide));
}

//optimised approach -> O(n^2)
//bottom up approach
//use bottom up approach and find diameter and height simultaneously
class Pair{
    public:
        int height;
        int diameter;
};

Pair fastDiameter(node* root){
    Pair p;
    if(root==NULL){
        p.diameter = p.height = 0;
        return p;
    }
    //otherwise
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height , right.height)+1;
    p.diameter = max(left.height + right.height , max(left.diameter , right.diameter));
    return p;
}


//Binary Tree sum replacement
//replace the value of each node by the sum of it's children nodes
//without changing the leaf nodes
int replaceSum(node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL and root->right==NULL){
        return root->data;
    }
    //recursive part
    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;
    return temp+root->data;
}

int main(){
    //building tree
    node* root = buildTree();

    // //PRINTING TREE
    // //printPreOrder
    // printPreOrder(root);
    // cout<<endl;
    // //printInOrder
    // printInOrder(root);
    // cout<<endl;
    // //printPostOrder
    // printPostOrder(root);
    // cout<<endl;

    // //print height of the tree
    // cout<<height(root)<<endl;

    // //print kth level of the tree
    // printKthLevel(root , 3);
    // cout<<endl;

    // //print all level
    // printAllLevel(root);

    // //Level Order Traversal
    // //bfs
    // bfsWithoutNewLine(root);
    // cout<<endl;
    
    // bfsWithNewLine(root);
    // cout<<endl;

    // //count all the nodes
    // cout<<count(root)<<endl;
    
    // //Sum of all nodes of the tree
    // cout<<SumOfAllNodes(root)<<endl;

    //finding diameter of tree
    //cout<<diameterOfTree(root)<<endl;
    // Pair p = fastDiameter(root);
    // cout<<p.height<<endl;
    // cout<<p.diameter<<endl;


    //SumReplacement
    // bfsWithNewLine(root);
    // cout<<endl;
    // replaceSum(root);
    // bfsWithNewLine(root);
    // cout<<endl;

    
    return 0;
}

//input : 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
