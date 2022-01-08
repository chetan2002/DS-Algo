#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	vector<ll> v(7);
		for(auto &c: v) {
			cin>>c;
		}
		cout<<v[0]<<" "<<v[1]<<" ";
		if(v[2]==v[0]+v[1]) {
			cout<<v[3]<<endl;
		}else{
			cout<<v[2]<<endl;
		}

    }
    return 0;
}