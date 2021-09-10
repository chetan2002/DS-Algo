#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	vector<int> v(n);
    	bool z = false;
    	for(auto &c: v){
    		cin>>c;
    		if(c==0){
    			z = true;
    		}
    	}

    	if(!z){
    		cout<<n+1<<" ";
    		for(int i=1;i<=n;i++){
    			cout<<i<<" ";
    		}
    		cout<<endl;
    		continue;
    	}

    	if(v[n-1]==0){
    		for(int i=0;i<=n;i++){
    			cout<<i+1<<" ";
    		}
    		cout<<endl;
    		continue;
    	}
    	bool done = false;
    	for(int i=0;i<n;i++){
    		if(!done and i!=n-1 and v[i]==0 and v[i+1]==1){
    			done = true;
    			cout<<i+1<<" "<<n+1<<" ";
    		}else{
    			cout<<i+1<<" ";
    		}
    	}
    	cout<<endl;
    }
    return 0;
}