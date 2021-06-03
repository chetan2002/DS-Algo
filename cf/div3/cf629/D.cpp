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

    	vector<ll> a(n);
    	for(auto &i: a){
    		cin>>i;
    	}

    	if(count(a.begin(),a.end() , a[0])==n){
    		cout<<1<<endl;
    		for(auto c: a){
    			cout<<1<<" ";
    		}
    		cout<<endl;
    		continue;
    	}

    	if(n%2==0){
    		cout<<2<<endl;
    		for(int i=0;i<n;i++){
    			cout<<i%2+1<<" ";
    		}
    		cout<<endl;
    		continue;
    	}

    	bool answer = false;
    	for(int i=0;i<n;i++){
    		if(a[i] == a[(i+1)%n]){
    			answer = true;
    			vector<int> ans(n);
    			for(int j=0,pos=i+1;pos<n;++pos,j^=1){
    				ans[pos] = j+1;
    			}
    			for(int j=0 , pos = i;pos>=0;--pos,j^=1){
    				ans[pos] = j+1;
    			}
    			cout<<2<<endl;
    			for(int pos = 0 ;pos<n;pos++){
    				cout<<ans[pos]<<" ";
    			}
    			cout<<endl;
    			break;
    		}
    	}

    	if(answer){
    		continue;
    	}
    	cout<<3<<endl;
    	for(int i=0;i<n-1;i++){
    		cout<<i%2+1<<" ";
    	}
    	cout<<3<<endl;

    }
    return 0;
}