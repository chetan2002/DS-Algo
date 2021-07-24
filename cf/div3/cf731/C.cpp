#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll k , n , m;
    	cin>>k>>n>>m;
    	vector<ll> vn(n);
    	vector<ll> vm(m);
    	for(auto &i: vn){
    		cin>>i;
    	}
    	for(auto &i: vm){
    		cin>>i;
    	}
    	vector<ll> ans(n+m);
    	int i=0 , j=0;
    	bool pos = true;
    	for(int l=0;l<n+m;l++){
    		if(i==n){
    			if(vm[j]==0){
    				ans[l]=0;
    				j++;
    				k++;
    				continue;
    			}
    			if(vm[j]<=k){
    				ans[l]=vm[j];
    				j++;
    				continue;
    			}else{
    				pos = false;
    				break;
    			}
    		}else
    		if(j==m){
    			if(vn[i]==0){
    				ans[l]=0;
    				i++;k++;
    				continue;
    			}
    			if(vn[i]<=k){
    				ans[l]=vn[i];i++;
    				continue;
    			}else{
    				pos = false;
    				break;
    			}
    		}else{
    			if(vn[i]==0){
    				ans[l]=0;i++;k++;
    			}else
    			if(vm[j]==0){
    				ans[l]=0;j++;k++;
    			}else
    			if(vn[i]<=k){
    				ans[l]=vn[i];i++;
    			}else
    			if(vm[j]<=k){
    				ans[l]=vm[j];j++;
    			}else{
    				pos = false;
    				break;
    			}
    		}
    	}
    	if(pos){
    		for(auto c: ans){
    			cout<<c<<" ";
    		}
    		cout<<endl;
    	}else{
    		cout<<"-1"<<endl;
    	}
    }
    return 0;
}