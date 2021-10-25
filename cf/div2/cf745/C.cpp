#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> sumPrefix;

void preprocess(vector<string> &v) {
	int n = v.size();
	int m = v[0].size();
	for(int i=0;i<m;i++) {
		sumPrefix[0][i] = (v[0][i]-'0');
	}
	for(int i=1;i<v.size();i++) {
		for(int j=0;j<v[0].size();j++) {
			sumPrefix[i][j] = (v[i][j]- '0' )+ sumPrefix[i-1][j];
		}
	}

	for(int i=0; i<v.size(); i++) {
		for(int j=1; j<v[0].size(); j++) {
			sumPrefix[i][j] += sumPrefix[i][j-1];
		}
	}
}

ll query(int a , int b, int c , int d) {
	ll res = sumPrefix[c][d];
	if(a>0) {
		res -= sumPrefix[a-1][d];
	}
	if(b>0){
		res -= sumPrefix[c][b-1];
	}
	if(a>0 and b>0) {
		res += sumPrefix[a-1][b-1];
	}
	return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n, m;
    	cin>>n>>m;
    	vector<string> v(n);
    	sumPrefix.clear();
    	for(auto &c: v) {
    		cin>>c;
    	}
    	sumPrefix.resize(n, vector<ll>(m,0));
    	preprocess(v);
    	

    	// for(auto c: sumPrefix) {
    	// 	for(auto a: c) {
    	// 		cout<<a<<" ";
    	// 	}
    	// 	cout<<endl;
    	// }
    	ll minians = INT_MAX;
    	for(int i=0; i<n-4; i++) {
    		for(int j=0; j<m-3; j++) {
 				int k = i+4 , l = j+3;
    			while(k<n and l<m) {
					ll hor = k-i-1;
					ll vert = l-j-1;
					ll left = hor - query(i+1,j, k-1 , j);
					ll right = hor - query(i+1, l, k-1, l) ;
					ll top = vert - query(i, j+1, i, l-1);
					ll bottom = (vert - query(i, j+1, i, l-1) );
					ll mid = query(i+1, j+1, k-1, l-1);
					// cout<<left<<" "<<right<<" "<<top<<" "<<bottom<<endl;
					minians = min(minians, left + right+ top + bottom + mid);

					k++, l++;
				}
			
    		}
    	}
    	cout<<minians<<endl;
    }
    return 0;
}