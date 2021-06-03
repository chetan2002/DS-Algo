#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n , m;
    	cin>>n>>m;
    	string s;
    	cin>>s;

    	bool allZ = true;;
    	for(auto c: s){
    		if(c=='1'){
    			allZ = false;
    			break;
    		}
    	}

    	if(allZ){
    		cout<<s<<endl;
    		continue;
    	}

    	string allO(n,'1');
    	for(int i=0;i<min(m,10000ll);i++){
    		string newS(n,'0');

    		if(s==allO){
    			break;
    		}
			for(int j=0;j<n;j++){
				if(s[j]=='1'){
					newS[j]='1';
					continue;
				}
				if(j==0){
					if(s[1]=='1'){
						newS[j]='1';
					}
				}else
				if(j==n-1){
					if(s[n-2]=='1'){
						newS[j]='1';
					}
				}else{
					if(s[j-1]=='1' and s[j+1]=='0'){
						newS[j]='1';
					}else
					if(s[j-1]=='0' and s[j+1]=='1'){
						newS[j] = '1';
					}
				}
			}
			s = newS;    		
    	}

    	cout<<s<<endl;

    }
    return 0;
}