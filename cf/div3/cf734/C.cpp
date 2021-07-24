#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;cin>>n;
    	vector<string> v(n);
    	for(auto &i: v){
    		cin>>i;
    	}

    	vector<vector<int>> freq(n,vector<int>(5,0));
    	for(int i=0;i<n;i++){
    		for(auto c: v[i]){
    			freq[i][c-'a']++;
    		}
    	}
    	ll ans = 0;
    	for(int i=0;i<5;i++){
    		vector<int> val;
    		for(int j=0;j<n;j++){
    			string s1 = v[j];
    			int n1 = s1.size();
    			int count = freq[j][i];
    			int diff = 2*count - n1;
    			val.push_back(diff);
    		}

    		sort(val.begin(),val.end(), greater<int>());
    		int last = 0;
    		for(ll k=0;k<n;k++){
    			last += val[k];
    			if(last>0){
    				ans = max(ans , k+1);
    			}
    		}
    	}
    	cout<<ans<<endl;
    }
    return 0;
}