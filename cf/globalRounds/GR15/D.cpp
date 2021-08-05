#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n;
vector<int> v;
vector<int> ans;

bool possible(int i){

	if(i==n){
		if(check()){
			return true;
		}
		return false;
	}
	if(i<3){
		int maxi = INT_MIN;
		int mini = INT_MAX;
		for(auto c: v){
			maxi = max(maxi , c);
			mini = min(mini , c);
		}

		ans[1] = 
	}
	for(int k=0;k<=i;k++){
		ans[i+1] = ans[k]-
	}
	
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	cin>>n;
    	v.clear();
    	v.resize(n);
    	for(auto &c: v){
    		cin>>c;
    	}
    	ans.clear();
    	ans.resize(n);
    	ans[0]=0;
    	if(possible(0)){
    		cout<<"YES"<<endl;
    	}else{
    		cout<<"NO"<<endl;
    	}
    }
    return 0;
}