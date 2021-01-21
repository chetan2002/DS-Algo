 #include<bits/stdc++.h>
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

//preorder
void printPreOrder(node* root){
    if(root == NULL){
        return ;
    }
    //otherwise , print the root first followed by subtrees(children)
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

//print bst level order
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

//insert in bst
node* InsertInBST(node* root , int data){
    //base case
    if(root == nullptr){
        root = new node(data);
        return root;
    }

    //recursive case
    if(data <= root->data){
        root->left = InsertInBST(root->left , data);
    }else{
        root->right = InsertInBST(root->right , data);
    }
    return root;
}
node* buildTree(){
    node* root = nullptr;
    int data;
    cin>>data;
    while(data != -1){
        root = InsertInBST(root , data);
        cin>>data;
    }
    return root;
}

node* searchBST(node* root , int key){
    if(!root){
        return root;
    }
    if(root->data == key){
        return root;
    }else
    if(root->data > key){
        return searchBST(root->left , key);
    }else{
        return searchBST(root->right , key);
    }
}

void printBSTInRange(node* root , int k1 ,  int k2){
    if(root==nullptr){
        return ;
    }
    if(root->data>=k1){
        printBSTInRange(root->left , k1 , k2);
    }
    if(root->data<=k2 and root->data>=k1){
        cout<<root->data<<" ";
    }
    if(root->data<=k2){
        printBSTInRange(root->right , k1 , k2);
    }

}

 int main(){
     node* root = nullptr;
     root = buildTree();
    PrintLevelOrder(root);
    //  node* found = searchBST(root , 5);
    //  if(found == nullptr){
    //      cout<<"NOT fOUND"<<endl;
    //  }else{
    //      cout<<"FOUND"<<endl;
    //  }
    cout<<endl;
    // printBSTInRange(root , 10 , 20);
     return 0;
 }

 //input
 //8 3 10 1 6 4 7 13 14 15 -1