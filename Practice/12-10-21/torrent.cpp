#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class values {
public: 
	int speed;
	bool isEvil;
	values(){
		speed = -1;
		isEvil = false;
	}
};
values* mp;
vector<vector<int>> v;

int dfs(int node) {
	if(mp[node].speed!=-1) {
		return mp[node].speed;
	}
	if(mp[node].isEvil) {
		for(auto c: v[node]) {
			if(mp[node].speed==-1) {
				mp[node].speed = dfs(c);
			}else{
				mp[node].speed = min(mp[node].speed, dfs(c));
			}
		}
	}else{
		for(auto c: v[node]) {
			mp[node].speed = max(mp[node].speed, dfs(c));
		}
	}
	return mp[node].speed;
}
int torrenting(int cbase, int* abase, int ctotal, int cconn, int aconn[][2], int cevil, int* aevil) {
	mp = new values[ctotal];
	for(int i=0; i<cbase; i++) {		
		mp[i].speed = abase[i];
	}
	for(int i=0; i<cevil; i++){
		mp[aevil[i]].isEvil = true;
	}
	v.clear();
	v.resize(ctotal);
	for(int i=0; i<cconn; i++) {
		v[aconn[i][1]].push_back(aconn[i][0]);

	}
	for(int i=0;i<ctotal; i++) {
		values c(mp[i]);
	}
	return dfs(ctotal-1);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n;cin>>n;
 	int base[n];
 	for(int i=0;i<n;i++) {
 		cin>>base[i];
 	}
 	int inp3;cin>>inp3;
 	int inp4;cin>>inp4;
 	int arr[inp4][2];
 	for(int i=0;i<inp4;i++) {
 		cin>>arr[i][0];
 		cin>>arr[i][1];
 	}
 	int inp5;cin>>inp5;
 	int evil[inp5];
 	for(int i=0;i<inp5;i++) {
 		cin>>evil[i];
 	}
 	cout<<torrenting(n, base, inp3, inp4, arr, inp5, evil)<<endl;
    return 0;
}