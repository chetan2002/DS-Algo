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

//is BST balanced
class Pair{
    public:
        int height;
        bool Balanced;
}; 
Pair isBalanced(node* root){
    Pair p;

    if(!root){
        return p;
    }

     Pair left = isBalanced(root->left);
     Pair right = isBalanced(root->right);

     p.height = max(left.height , right.height)+1;

     if(left.Balanced and right.Balanced and (abs(left.height - right.height)<=1)){
         p.Balanced = true;
     }else{
         p.Balanced = false;
     }
     return p;
}

class LinkedList{
    public:
        node* head;
        node* tail;
        LinkedList(){
            head = tail = nullptr;
        }
};

LinkedList BSTtoLL(node* root){
    LinkedList l ;
    //base case
    if(!root){
        return l;
    }

    //recursive case
    if(root->left == nullptr and root->right == nullptr){
        l.head = l.tail = root;
    }else
    if(root->left!=nullptr and root->right == nullptr){
        LinkedList left = BSTtoLL(root->left);
        left.tail->right = root;
        l.head = left.head;
        l.tail = root;
    }else 
    if(root->left==nullptr and root->right!=nullptr){
        LinkedList right = BSTtoLL(root->right);
        root->right = right.head;
        l.head = root;
        l.tail = right.tail;
    }else{
        LinkedList left = BSTtoLL(root->left);
        LinkedList right = BSTtoLL(root->right);

        left.tail->right = root;
        root->right = right.head;
        l.head = left.head;
        l.tail = right.tail;
    }
    
    return l;
}

void printLL(node* head){
    if(head == nullptr){
        return;
    }
    cout<<head->data<<" ";
    printLL(head->right);
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

//printing the right view
void RightView(node* root , int curr , int &maxi){
    //base case
    if(root==nullptr){
        return;
    }

    //recursive
    if(curr>maxi){
        cout<<root->data<<" ";
        maxi = curr;
    }
    RightView(root->right , curr+1 , maxi);
    RightView(root->left , curr+1 , maxi);
   
    
    return;
}

 int main(){
    // node* root = nullptr;
    //  root = buildTree();
    // PrintLevelOrder(root);
    //  node* found = searchBST(root , 5);
    //  if(found == nullptr){
    //      cout<<"NOT fOUND"<<endl;
    //  }else{
    //      cout<<"FOUND"<<endl;
    //  }
    //cout<<endl;
    // printBSTInRange(root , 10 , 20);


    // Pair p;
    // p =isBalanced(root);
    // if(p.Balanced){
    //     cout<<"Balanced"<<endl;
    // }else{
    //     cout<<"Not Balanced"<<endl;
    // }


    // LinkedList l1 = BSTtoLL(root);
    // printLL(l1.head);


    int arr[] = {1 , 2 , 3 , 4 , 5 , 8 , 9 , 10};
    int n = sizeof(arr)/sizeof(int);
    node* root = CreateBSTBalancedUsingSortedArray(arr , 0 , n-1);

    PrintLevelOrder(root);
    cout<<endl;

    //DELETING A NODE IN BST

    // DeleteInBST(root , 8);
    // PrintLevelOrder(root);


    //PRINTING RIGHT VIEW OF A TREE
    int maxi = -1;
    RightView(root , 0 , maxi);

     return 0;
 }

 //input
 //8 3 10 1 6 4 7 13 14 15 -1
 src=""