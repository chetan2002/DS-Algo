#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<string> vs;
vector<int> pos = {-1, 0, 1, 0, -1};

bool validPos(int i, int j) {
	if(i<0 or j<0 or i>=n or j>=m) {
		return false;
	}
	if(vs[i][j]=='#') {
		return false;
	}
	return true;
}
void removeRooms(int i, int j) {
	if(!validPos(i,j)) {
		return;
	}
	vs[i][j] = '#';
	for(int k=1; k<=4; k++) {
		removeRooms(i+pos[k-1], j+pos[k]);
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	cin>>n>>m;
 	vs.resize(n);
 	for(auto &c: vs) {
 		cin>>c;
 	}

 	ll count =0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(vs[i][j]=='.') {
				count++;
				removeRooms(i,j);
			}
		}
	} 	
	cout<<count<<endl;
    return 0;
}