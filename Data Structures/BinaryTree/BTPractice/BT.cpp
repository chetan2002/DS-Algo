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

//diameter fast
class Pair{
    public:
        int height;
        int diameter;
};

Pair fastDiameter(node* root){
    if(root==nullptr){
        Pair p;
        p.height = 0;
        p.diameter = 0;
        return p;
    }
    Pair p;

    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height , right.height)+1;
    
    int op1 =  left.height + right.height;
    int op2 = left.diameter;
    int op3 = right.diameter;

    p.diameter = max(op1 , max(op2 , op3));
    return p;
}
//8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1

int sum(node* root){
    if(root == nullptr){
        return 0;
    }
    return root->data + sum(root->left) + sum(root->right);
}

void PrintLevelOrder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        node* x = q.front();
        q.pop();
        if(x == nullptr){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }else{
            cout<<x->data<<" ";
            if(x->left != nullptr){
                q.push(x->left);
            }
            if(x->right != nullptr){
                q.push(x->right);
            }
        }
    }
}

node* buildTreeLevel(){
    node* root = nullptr;
    int data ;
    cout<<"Enter root data";
    cin>>data;
    if(data == -1){
        return nullptr;
    }

    root = new node(data);
    queue<node*> q;
    while(!q.empty()){
        node* x = q.front();
        q.pop();

        cout<<"Enter data of "<<x->data<<endl;
        int left_data , right_data;
        cin>>left_data>>right_data;
        if(left_data != -1){
            x->left = new node(left_data);
        }
        if(right_data != -1){
            x->right = new node(right_data);
            q.push(x->right);
        }
    }
    return root;
}

//Create Tree using Inorder and Preorder
int pre[] = {8,3,1,6,4,7,10,14,13};
int i= 0;
int in[] = {1,3,4,6,7,8,10,13,14};

node* CreateTree(int s , int e){
    //base case
    if(s>e){
        return nullptr;
    }
    //recursive case
    int d=pre[i++];
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

int main(){
    // node* root;
    // root = buildTree();
    // cout<<"Count Nodes : "<<CountNodes(root)<<endl;
    // cout<<"Height : "<<height(root)<<endl;
    // cout<<"Diameter :"<<Diameter(root)<<endl;
    // // Pair p = fastDiameter(root);
    // // cout<<"Fast H "<<p.height<<endl;
    // // cout<<"Fast D "<<p.diameter<<endl;
    // cout<<sum(root)<<endl;

    int n = sizeof(in)/sizeof(int);
    node* root = CreateTree(0 , n-1);

    PrintLevelOrder(root);
    
    return 0;
}