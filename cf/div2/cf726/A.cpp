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
    	double sum = 0;
    	vector<int> v(n);
    	for(auto &c: v){
    		cin>>c;
    		sum+=c;
    	}
    	double avg = sum/n;
    	if(avg==1){
    		cout<<"0"<<endl;
    		continue;
    	}
    	if(avg<1){
    		cout<<"1"<<endl;
    	}else{
    		cout<<sum-n<<endl;
    	}

    }
    return 0;
}