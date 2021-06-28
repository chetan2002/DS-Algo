#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){

    	string s;
    	cin>>s;

    	ll count = 0;

    	ll last0 = -1 , last1 = -1;
    	int i=0 , j = 0 ;
    	ll maxAns = 0;
    	while(j<s.length() and i<=j){
    		// cout<<"update: "<<last1<<" "<<last0<<" "<<endl;
    		if(s[j]=='?'){
    			j++;
    		}else
    		if(s[j]=='1'){
    			if(last1<i){
    				if(last0<i){
    					j++;
						last1 = j-1;
    				}else{
    					int val = i-last0;
    					if(val%2==0){
    						maxAns+=(j-i);
    						// cout<<j<<" "<<i<<endl;
    						i++;
    					}else{
    						j++;
    						last1 = j-1;

    					}
    				}
    			}else{
    				if(last0<i){
    					int val = i-last1;
    					if(val%2==1){
    						maxAns+=(j-i);
    						// cout<<j<<" "<<i<<endl;
    						i++;
    					}else{
    						j++;    			
    						last1 = j-1;
    					}
    				}else{
    					int val1 = i-last1;
    					int val2 = i-last0;
    					if(val1%2==0 and val2%2!=0){
    						j++;
    						// cout<<"i am working for "<<j<<" "<<i<<endl;
			    			last1 = j-1;
    					}else{
    						maxAns+=(j-i);
    						// cout<<j<<" "<<i<<endl;

    						i++;
    					}
    				}
    			}
    		}else
    		if(s[j]=='0'){
    			if(last0<i){
    				if(last1<i){
    					j++;
						last0 = j-1;
    				}else{
    					int val = i-last1;
    					if(val%2==0){
    						maxAns+=(j-i);
    						// cout<<j<<" "<<i<<" "<<last1<<endl;
    						i++;
    					}else{
    						last0 = j;
    						j++;

    					}
    				}
    			}else{
    				if(last1<i){
    					int val = i-last0;
    					if(val%2==1){
    						maxAns+=(j-i);
    						// cout<<j<<" "<<i<<endl;
    						i++;
    					}else{
    						j++;
    						last0 = j-1;
    					}
    				}else{
    					int val1 = i-last0;
    					int val2 = i-last1;
    					if(val1%2==0 and val2%2!=0){
    						j++;
    						last0 = j-1;
    					}else{
    						maxAns+=(j-i);
    						// cout<<j<<" "<<i<<endl;
    						i++;
    					}
    				}
    			}
    		}

    		// cout<<i<<" "<<j<<" "<<last1<<" "<<last0<<endl;
    	}
    	maxAns+= ((j-i+1)*(j-i))/2;
    	// cout<<j<<" "<<i<<endl;
    	cout<<maxAns<<endl;
    }
    return 0;
}