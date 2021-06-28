#include<bits/stdc++.h>
using namespace std;
#define ll long long int

unordered_map<string , vector<int>> nodePath;
unordered_map<string,string> locked;
unordered_map<string ,int> mp;
class tree{
public:
	string name ;
	vector<int> rasta;
	vector<tree*> bache;
	tree(string X ,vector<int> r , int i ){
		name = X;
		rasta = r;
		rasta.push_back(i);
	}
};
tree* head=nullptr;

void buildTree(tree* head ,int n, int m){
	if(n<=0){
		return;
	}
	queue<tree*> q;
	q.push(head);
	while(n>0 and !q.empty()){
		auto p = q.front();
		q.pop();
		nodePath[p->name] = p->rasta;
		for(int i=0;i<m;i++){
			string name;
			cin>>name;
			// cout<<name<<" ";

			tree* node= new tree(name , p->rasta , i);
			p->bache.push_back(node);
			n--;
			nodePath[name] = p->bache[i]->rasta;
			if(n>=m){
				q.push(p->bache[i]);
			}
		}
	}
}

bool lock(string s , string uId){
	vector<int> path = nodePath[s];
	vector<string> v;
	int i=1;
	tree* node = head;
	if(locked.find(node->name)!=locked.end()){
		return false;
	}
	if(mp[s]!=0){
		return false;
	}
	v.push_back(node->name);
	while(i<path.size()){
		node = node->bache[path[i]];
		v.push_back(node->name);
		i++;
		if(locked.find(node->name)!=locked.end()){
			return false;
		}
	}
	locked[s] = uId;
	for(auto c: v){
		mp[c]++;
	}
	return true;
}

bool unlock(string s , string uId){
	if(locked[s]!=uId){
		return false;
	}
	vector<int> path = nodePath[s];
	vector<string> v;
	int i=1;
	tree* node = head;
	v.push_back(node->name);
	while(i<path.size()){
		node = node->bache[path[i]];
		v.push_back(node->name);
		i++;
	}
	locked.erase(s);
	for(auto c: v){
		mp[c]--;
	}
	return true;
}

bool upgradeLock(string s , string uId){

	//uncomment if leaf node can't be upgraded
	// if(mp[s]==0){
	// 	return false;
	// }
	if(locked.find(s)!=locked.end()){
		return false;
	}
	vector<int> path = nodePath[s];	
	bool pos = true;
	tree* node = head;
	int i=1;
	while(i<path.size()){
		node = node->bache[path[i]];
		i++;
	}

	vector<tree*> v = node->bache;
	for(auto c: v){
		if(locked[c->name]!=uId){
			pos = false;
		}
	}
	if(!pos){
		return false;
	}
	for(auto c: v){
		unlock(c->name , uId);
	}
	bool valid= lock(s , uId);
	if(!valid){
		for(auto c: v){
			lock(c->name , uId);
		}
	}
	return valid;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , m , q;
    cin>>n>>m>>q;

    if(n>0){
	    string name ;
	    cin>>name;
	    head = new tree(name , {} , 0);    	
	    n--;
    }
    buildTree(head , n, m);
    while(q--){
    	int ch;
    	string name , us;
    	cin>>ch>>name>>us;
    	bool ans = false;
    	if(ch==1){
    		ans=lock(name , us);
    	}else
    	if(ch==2){
    		ans=unlock(name , us);
    	}else
    	if(ch==3){
    		ans=upgradeLock(name , us);
    	}
    	if(ans){
    		cout<<"true"<<endl;
    	}else{
    		cout<<"false"<<endl;
    	}
    }
    return 0;
}