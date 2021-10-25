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
    	string s1 , s2;
    	cin>>s1>>s2;

    	int answer= 0;
    	for(int i=0; i<n; i++) {
    		if(s1[i]=='0' and s2[i]=='1') {
    			answer+=2;
    		}else
    		if(s1[i]=='1' and s2[i]=='0') {
    			answer+=2;
    		}else
    		if(s1[i]=='0' and s2[i]=='0') {
    			if(i<n-1) {
    				if(s1[i+1]=='1' and  s2[i+1]=='1') {
    					answer+=2;
    					i++;
    					continue;
    				}
    			}
    			answer+=1;
    		}else {
    			if(s1[i]=='1' and s2[i]=='1') {
    				if(i<n-1) {
    					if(s1[i+1]!='1' or s2[i+1]!='1') {
    						answer+=2;
    						i++;
    						continue;
    					}
    				}
    			}
    		}
    	}

    	cout<<answer<<endl;

    }
    return 0;
}