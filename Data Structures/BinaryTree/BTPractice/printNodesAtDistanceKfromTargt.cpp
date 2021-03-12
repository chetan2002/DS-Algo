//https://hack.codingblocks.com/app/contests/2022/350/problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

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

//Create Tree using Inorder and Preorder
int pre[1005];
int pos= 0;
int in[1005];

node* CreateTree(int s , int e){
    //base case
    if(s>e){
        return nullptr;
    }
    //recursive case
    int d=pre[pos++];
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

vector<int> v;
void printAtLevelK(node* root , int k){
	if(root== nullptr){
		return;
	}
	if(k==0){
		v.push_back(root->data);
		return;
	}
	printAtLevelK(root->left , k-1 );
	printAtLevelK(root->right , k-1);
	return;
}

int printAtDistanceK(node* root , int target , int k){
	if(root == nullptr){
		return -1;
	}
	if(root->data==target){
		printAtLevelK(root , k);
		return 0;
	}

	int DL = printAtDistanceK(root->left , target , k );

	if(DL != -1){

		if(DL+1 == k){
			v.push_back(root->data);
		}else{
			printAtLevelK(root->right , k-2-DL);
		}
		return 1+DL;
	}

	int DR = printAtDistanceK(root->right , target , k);
	if(DR!=-1){
		if(DR+1 == k){
			v.push_back(root->data);
		}else{
			printAtLevelK(root->left , k-2-DR);
		}
		return 1+DR;
	}
	return -1;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>pre[i];
	}
	for(int i=0;i<n;i++){
		cin>>in[i];
	}

	node* root= CreateTree(0 , n-1);

	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		v.clear();
		int val , k;
		cin>>val>>k;
		printAtDistanceK(root , val , k );
		sort(v.begin() , v.end());
		for(auto c: v){
			cout<<c<<" ";
		}
		if(v.size()==0){
			cout<<"0";
		}
		cout<<endl;
	}


	return 0;
}