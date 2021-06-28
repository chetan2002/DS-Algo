#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	vector<ll> v(n);
    	for(auto &c: v){
    		cin>>c;
    	}

    	sort(v.begin(),v.end());
    	int i=0 ,  j=n-1;
    	vector<ll> vn(n);
    	for(int k=0;k<n and i<=j;k++){
    		if(k%2==0){
    			vn[k]=v[i++];
    		}else{
    			vn[k]=v[j--];
    		}
    	}
    	reverse(vn.begin(),vn.end());
    	for(auto c: vn){
    		cout<<c<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}