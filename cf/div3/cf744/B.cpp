#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void shift(vector<ll> &v, int i , int j) {
	int val = v[i];
	for(int k=j;k>i;k--){
		v[k] = v[k-1];
	}
	v[i] = v[j];
}

void bubbleSortCount(vector<ll> v, vector<vector<ll>> &a) {
	vector<ll> b = v;
	sort(b.begin() , b.end());
	for(int i=0;i<v.size()-1;i++) {
		if(v[i]==b[i]) {
			continue;
		}else{
			int j=i+1;
			while(v[j]!=b[i]){
				j++;
			}
			a.push_back({i+1, j+1, j-i});
			shift(v, i, j);;
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	vector<ll> v(n);
    	for(auto &c: v) {
    		cin>>c;
    	}
    	vector<vector<ll>> a;
    	bubbleSortCount(v, a);
    	cout<<a.size()<<endl;
    	for(auto c: a) {
    		cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<endl;
    	}
    }
    return 0;
}