#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int d){
        data= d;
        left = nullptr;
        right = nullptr;
    }    
};

node* createTree(){
    int d;
    cin>>d;
    if(d==-1){
        return nullptr;
    }
    node* root= new node(d);
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* nn = q.front();
        q.pop();
        int l , r;
        cin>>l>>r;
        if(l==-1){
            nn->left = nullptr;
        }else{
            nn->left = new node(l);
            q.push(nn->left);
        }
        if(r==-1){
            nn->right = nullptr;
        }else{
            nn->right = new node(r);
            q.push(nn->right);
        }
    }
    return root;
}

void preorder(node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void bottomView(node* root){
    if(root==nullptr){
        return ;
    }
    map<int , int> mp;
    queue<pair<node* , int>> q;
    q.push({root , 0});
    while(!q.empty()){
        pair<node* , int> p = q.front();
        q.pop();
        node* n = p.first;
        int pos = p.second;
        mp[pos] = n->data;
        if(n->left!=nullptr){
            q.push({n->left , pos-1});
        }
        if(n->right!=nullptr){
            q.push({n->right , pos+1});
        }
    }

    for(auto c: mp){
        cout<<c.second<<" ";
    }
}

void topView(node* root){
    if(root==nullptr){
        return;
    }
    map<int,int> mp;
    queue<pair<node* , int>> q;
    q.push({root , 0});
    while(!q.empty()){
        pair<node* , int> p = q.front();
        q.pop();
        node* n = p.first;
        int pos = p.second;
        if(mp.find(pos)==mp.end()){
            mp[pos] = n->data;
        }
        if(n->left!=nullptr){
            q.push({n->left , pos-1});
        }
        if(n->right!=nullptr){
            q.push({n->right , pos+1});
        }
    }

    for(auto c: mp){
        cout<<c.second<<" ";
    }

}


int main(){
    node* root = createTree();
    topView(root);
    bottomView(root);
    // preorder(root);
    return 0;
}