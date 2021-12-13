#include<bits/stdc++.h>
using namespace std;

vector<int> adj(5001);
bool visited[5001];
bool dfs(int start, int end){
	if(start==end){
		return true;
	}

	visited[start]=1;
	for(auto x: adj[start]){
		if(!visited[x]){
			if(dfs(x,end)){
				return true;
			}
		}
	}
	return false;

}


int main(){

	int n; 
	cin>>n; 
	vector<int>members; 
	for(int i=0;i<n;i++){ 
	    int x; 
	    cin>>x; 
	    members.push_back(x); 
	} 
	int end; 
	cin>>end; 
	for(int i=0;i<end;i++){ 
	    int x,y; 
	    cin>>x>>y; 
	    adj[x].push_back(y); 
	} 
	int n1,n2; 
	cin>>n1>>n2; 
	if(dfs(n1,n2)){ 
	    cout<<"1"; 
	} 
	else{
	    cout<<"0"; 
	}
	return 0;
}