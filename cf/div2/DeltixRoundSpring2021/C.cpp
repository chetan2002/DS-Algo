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

    	vector<int> v(1);
    	cin>>v[0];
    	cout<<v[0]<<endl;;
    	for(int i=0;i<n-1;i++){
    		int a ;
    		cin>>a;
    		if(a==1){
    			v.push_back(a);
    		}else{
    			int pos = 0;
    			for(int j=0;j<v.size();j++){
	    			if(v[j]==a-1){
	    				pos = j;
	    			}
	    		}	
	    		auto it = v.begin();
	    		v.erase(v.begin()+pos , v.end());
	    		v.push_back(a);
    		}
    		
    		string s = "";
    		for(auto c: v){
    			s+= to_string(c);
    			s+='.';
    		}
    		s= s.substr(0,s.length()-1);
    		cout<<s<<endl;
    	}

    }
    return 0;
}