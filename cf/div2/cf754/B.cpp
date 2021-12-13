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
    	string s;
    	cin>>s;
    	int i=0, j=n-1;
    	vector<int> v;
    	int lasti = 0, lastj = n-1;
    	while(i<j) {
    		while(j>=i and s[j]=='1') {
    			j--;
    		}
    		while(i<=j and s[i]=='0') {
    			i++;
    		}
    		if(i<j and s[i]=='1' and s[j]=='0') {
    			v.push_back(i+1);
    			v.push_back(j+1);
    			lasti = i;
    			lastj = j;
    		}
    		i++, j--;
    	}
    	sort(v.begin(), v.end());
    	if(v.size()==0) {
    		cout<<0;
    	}else{
    		cout<<1<<endl;
    		cout<<v.size()<<" ";
    		for(auto c: v) {
    			cout<<c<<" ";
    		}
    	}
    	cout<<endl;

    }
    return 0;
}