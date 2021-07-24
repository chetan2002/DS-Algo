#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	string s , t;
    	cin>>s>>t;

    	bool pos = false;
    	for(int i=0;i<t.length();i++){
    		string a = t.substr(0,i);
    		string b = t.substr(i);

    		reverse(b.begin() , b.end());

    		auto found = s.find(a);
    		while(found!=string::npos){
    			auto found2 = s.find(b);
    			while(found2!=string::npos){
    				if(found+a.length()==found2+b.length()-1){
    					// cout<<a<<endl;
    					// cout<<b<<endl;
    					// cout<<found<<" "<<found2<<endl;
    					pos = true;
    					break;
	    			}else{
	    				found2 =s.find(b,found2+1);
	    			}
    			}
    			found = s.find(a , found+1);
    			if(pos==true){
    				break;
    			}
    		}

    		if(pos==true){
    			break;
    		}
    	}
    	
    	if(pos){
    		cout<<"YES"<<endl;
    	}else{
    		cout<<"NO"<<endl;
    	}

    }
    return 0;
}