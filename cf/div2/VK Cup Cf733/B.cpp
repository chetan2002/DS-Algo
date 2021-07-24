#include<bits/stdc++.h>
using namespace std;
#define ll long long int


void put(vector<vector<int>> &v , int n , int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			bool put = true;
			if(i>0 and v[i-1][j]){
				put = false;
			}
			if(i>0 and j>0 and v[i-1][j-1]){
				put = false;
			}
			if(j>0 and v[i][j-1]){
				put = false;
			}
			if(i>0 and j<m-1 and v[i-1][j+1]){
				put = false;
			}
			if(i<n-1 and v[i+1][j]){
				put = false;
			}

			if(j<m-1 and v[i][j+1]){
				put = false;
			}

			if(i<n-1 and j>0 and v[i+1][j-1]){
				put = false;
			}

			if(i<n-1 and j<m-1 and v[i+1][j+1]){
				put = false;
			}

			if(put and (i==0 || j==0 || j==m-1 || i==n-1)){
				v[i][j] = 1;
			}
		}
	}
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	int n , m;cin>>n>>m;
    	vector<vector<int>> v(n, vector<int>(m,0));


    	put(v , n , m);

    	for(auto c: v){
    		for(auto a: c){
    			cout<<a;
    		}
    		cout<<endl;
    	}
    	cout<<endl;
    }
    return 0;
}