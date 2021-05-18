#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 5010;

int n, m , s;
vector<int> g[N];
vector<int> tg[N];
vector<int> ord;
bool used[N];
int comp[N];
int cnt = 0;
vector<int> cg[N];
bool ucomp[N];
int indeg[N];

void dfs1(int v){
	used[v] = true;
	for(auto to: g[v]){
		if(!used[to]){
			dfs1(to);
		}
	}
	ord.push_back(v);
}

void dfs2(int v){
	comp[v] = cnt;
	for(auto to: tg[v]){
		if(comp[to] == -1){
			dfs2(to);
		}
	}
}

void dfs3(int v){
	ucomp[v] = true;
	for(auto to: cg[v]){
		if(!ucomp[to]){
			dfs3(to);
		}
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	cin>>n>>m>>s;
 	--s;

 	for(int i=0 ; i < m ; ++i){
 		int x , y ;
 		cin>>x >> y ;
 		--x ; --y ;
 		g[x].push_back(y);
 		tg[y].push_back(x);
 	}

 	for(int i=0 ; i<n; i++){
 		if(!used[i]){
 			dfs1(i);
 		}
 	}
 	reverse(ord.begin() , ord.end());
 	memset(comp , -1 , sizeof(comp));

 	for(int i=0; i<n;i++){
 		if(comp[ord[i]] == -1){
 			dfs2(ord[i]);
 			++cnt;
 		}
 	}

 	for(int v = 0 ; v<n;v++){
 		for(auto to : g[v]){
 			if(comp[v] != comp[to]){
 				cg[comp[v]].push_back(comp[to]);
 				++indeg[comp[to]];
 			}
 		}
 	}
 	dfs3(comp[s]);
 	int ans = 0;
 	for(int i=0;i<cnt ;++i){
 		if(!ucomp[i] and indeg[i]==0){
 			++ans;
 		}
 	}
 	cout<<ans<<endl;
    return 0;
}