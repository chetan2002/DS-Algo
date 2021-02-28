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


node* CreateBSTBalancedUsingSortedArray(int *arr , int s , int e){
    //base case
    if(s > e) {
        return nullptr;
    }

    //recursive case
    int mid = (s + e)/2;
    node* root = new node(arr[mid]);
    root->left = CreateBSTBalancedUsingSortedArray(arr , s , mid-1);
    root->right = CreateBSTBalancedUsingSortedArray(arr , mid+1 , e);
    return root;
}



//deleting a node in BST
// 1. leaf node : no children , delete as it isBalanced
// 2. 1 children : attach children
// 3. 2 children : max of left or min of right

node* DeleteInBST(node* root , int key){
    //traverse to the node to be deleted
    if(root->data>key){
        root->left = DeleteInBST(root->left , key);
        return root;
    }else
    if(root->data<key){
        root->right = DeleteInBST(root->right , key);
        return root;
    }else{
        //root->data == key
        //1.no children
        if(!root->left and !root->right){
            delete root;
            return nullptr;
        }else 
        if(root->left and !root->right){
            //1 children on left
            node* temp = root->left;
            delete root;
            return temp;
        }else 
        if(!root->right and root->left){
            //1 children on right
            node* temp = root->right;
            delete root;
            return temp;
        }else{
            //2 children are present
            node* replace = root->right;
            while(replace->left){
                replace = replace->left;
            }
            swap(root->data , replace->data);
            root->right = DeleteInBST(root->right , replace->data);
            return root;
        }
        
    }
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr , arr+n);
        node* root = CreateBSTBalancedUsingSortedArray(arr , 0 , n-1);
        int m;
        cin>>m;
        while(m--){
            int key;
            cin>>key;
            root = DeleteInBST(root , key);
        }
        printPreOrder(root);
    }
    return 0;
}