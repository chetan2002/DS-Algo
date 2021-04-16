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

class BinaryTree{
    node* root;

    //destroy tree nodes
    void _destroy(node* temp){
        if(temp==nullptr){
            return ;
        }
        _destroy(temp->left);
        _destroy(temp->right);
        delete temp;
        temp = nullptr;
    }
    //buildtree helper
    node* _buildTree(){
        int d;
        cin>>d;
        if(d==-1){
            return nullptr;
        }else{
            node* temp = new node(d);
            temp->left = _buildTree();
            temp->right = _buildTree();
            return temp;
        }
    }

    //preorder helper
    void _preorder(node* temp){
        if(temp==nullptr){
            return;
        }
        cout<<temp->data<<" ";
        _preorder(temp->left);
        _preorder(temp->right);
    }
    

    //inorder helper
    void _inorder(node* temp){
        if(temp==nullptr){
            return;
        }
        _inorder(temp->left);
        cout<<temp->data<<" ";
        _inorder(temp->right);
    }
    
    //postorder helper
    void _postorder(node* temp){
        if(temp==nullptr){
            return;
        }
        _postorder(temp->left);
        _postorder(temp->right);
        cout<<temp->data<<" ";
    }

    //count nodes
    int _countNodes(node* temp){
        if(temp==nullptr){
            return 0;
        }
        return 1 + _countNodes(temp->left) + _countNodes(temp->right);
    }

    //height of tree
    int _height(node* temp){
        if(temp==nullptr){
            return 0;
        }

        int h1 = _height(temp->left);
        int h2 = _height(temp->right);
        
        return 1+ max(h1 , h2);
    }

    //slow diameter
    int _slowDiameter(node* temp){
        if(temp==nullptr){
            return 0;
        }
        //if it is in left part
        int op1 = _slowDiameter(temp->left);
        
        //if it is in right part
        int op2 = _slowDiameter(temp->right);

        //if it is via the current node
        int op3 = _height(temp->left) + _height(temp->right);

        return max(op1 , max(op2 , op3));
    }

    pair<int , int> _diameter(node* temp){
        pair<int , int> p;
        if(temp==nullptr){
            return {0 ,0};
        }
        pair<int , int> left = _diameter(temp->left);
        pair<int , int> right = _diameter(temp->right);

        p.second = max(left.second , right.second)+1;
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second+right.second;
        
        p.first = (op1 , max(op2 , op3));
        return p;
    }

    //sum of tree nodes
    int _sum(node* temp){
        if(temp==nullptr){
            return 0;
        }
        int v1 = _sum(temp->left);
        int v2 = _sum(temp->right);
        return temp->data + v1 + v2;
    }
    
    //mirror the tree
    void _mirror(node* temp){
        if(temp==nullptr){
            return;
        }
        swap(temp->left , temp->right);
        _mirror(temp->left);
        _mirror(temp->right);
    }
    

    //build tree using pre and inorder array
    node* _buildTree(vector<int> pre , vector<int> in , int s , int e , int &pos){
        if(s>e){
            return nullptr;
        }
        int d = pre[pos++];
        node* temp = new node(d);
        int k = -1;
        for(int j=s;j<=e;j++){
            if(in[j] == d){
                k=j;
            }
        }
        temp->left = _buildTree(pre , in , s , k-1 , pos);
        temp->right = _buildTree(pre , in , k+1 , e , pos);
        return temp;
    }
public:

    //constructor
    BinaryTree(){
        root=nullptr;
    }

    
    //destroy tree nodes 
    void destroy(){
        _destroy(root);
        root = nullptr;
    }


    //buildtree
    void buildTree(){
        destroy();
        root = _buildTree();
    }

    //preorder
    void preorder(){
        _preorder(root);
        cout<<endl;
    }

    //inorder
    void inorder(){
        _inorder(root);
        cout<<endl;
    }

    //postorder
    void postorder(){
        _postorder(root);
        cout<<endl;
    }

    //counting nodes
    int countNodes(){
        int ans =_countNodes(root);
        return ans;
    }

    //height of tree
    int height(){
        int ans = _height(root);
        return ans;
    }

    //diameter of tree
    int slowDiameter(){
        int ans = _slowDiameter(root);
        return ans;
    }

    int diameter(){
        pair<int , int> p = _diameter(root);
        return p.first;
    }

    //sum of tree nodes
    int sum(){
        int ans = _sum(root);
        return ans;
    }

    //mirror the tree
    void mirror(){
        _mirror(root);
    }

    //print level order
    void levelorder(){
        if(root==nullptr){
            return;
        }
        queue<node*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            node* n = q.front();
            q.pop();

            if(n==nullptr){
                cout<<endl;
                if(!q.empty()){
                    q.push(nullptr);
                }
            }else{
                cout<<n->data<<" ";
                if(n->left!=nullptr){
                    q.push(n->left);
                }
                if(n->right!=nullptr){
                    q.push(n->right);
                }
            }
        }
    }

    void buildLevelOrder(){
        destroy();
        int data;
        cin>>data;
        if(data==-1){
            root= nullptr;
        }
        queue<node*> q;
        
        root = new node(data);
        q.push(root);
        while(!q.empty()){
            node* n = q.front();
            q.pop();

            int left , right;
            cin>>left>>right;
            if(left!=-1){
                node* l = new node(left);
                n->left = l;
                q.push(l);
            }
            if(right!=-1){
                node* r = new node(right);
                n->right = r;
                q.push(r);
            }
        }
    }
    //building tree using pre and in order array
    void buildTree(vector<int> pre , vector<int> in , int n){
        destroy();
        int pos = 0;
        root = _buildTree(pre , in , 0 , n-1 , pos);
    }
};

int main(){
    BinaryTree b;
    //building tree
    b.buildTree();

    //printing tree
    b.preorder();
    b.inorder();
    b.postorder();

    //count tree nodes
    cout<<b.countNodes()<<endl;
    
    //height of tree
    cout<<b.height()<<endl;

    //diameter of tree
    cout<<b.diameter()<<endl;

    //sum of tree
    cout<<b.sum()<<endl;

    //print level order
    b.levelorder();
    // b.buildLevelOrder();
    // b.levelorder();

    vector<int> pre = {8, 3, 1, 6, 4, 7, 10, 14, 13};
    vector<int> in = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    b.buildTree(pre , in , pre.size());
    b.postorder();

    
    return 0;
}