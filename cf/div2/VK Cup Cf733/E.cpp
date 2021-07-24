#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	string st;
    	cin>>st;
    	int n = st.length();
    	map<char , ll> mp;
    	for(auto c: st){
    		mp[c]++;
    	}
    	string s="";
  		if(mp.size()==1){
  			s= st;
  		}else
    	if(mp.size()==2){
    		int count = 0;
    		char a , b;
    		ll a1 = 0 , b1 = 0;
    		for(auto c: mp){
    			if(count==0){
    				a = c.first;
    				a1 = c.second;
    			}else{
    				b = c.first;
    				b1 = c.second;
    				break;
    			}
    			count++;
    		}

    		if(a1==1){
    			s+=a;
    			string s2(b1,b);
    			s+=s2;
    		}else
    		if(b1==1){
    			s+=b;
    			string s2(a1,a);
    			s+=s2;
    		}else{
    			s+=a;
    			s+=a;
    			a1-=2;
    			s+=b;
    			b1--;
    			for(int i=0;s.length()<n;i++){
    				if(i%2==0 and a1!=0){
    					s+=a;
    					a1--;
    				}else
    				if(i%2==1 and b1!=0){
    					s+=b;
    					b1--;
    					if(b1==1 and a1>1){
    						// string s2(a1,a);
    						// s+=s2;
    						s+=b;
    						b1--;
    						// a1=0;
    					}
    				}
    			}
    		}
    	}else{
    		int count = 0;
    		char a , b;
    		int a1=0 , b1=0;
    		for(auto &c: mp){
    			if(count==3){
    				break;
    			}else{
    				s+=c.first;
    				c.second=c.second-1;
    				if(count==0){
    					if(c.second>0){
    						s+=c.first;
    						c.second=c.second-1;
    					}
    					a1=c.second;
    					a = c.first;
    				}
    				if(count==1){    					
						b=c.first;
						b1=c.second;

						for(int i=0;a1+b1>0;i++){
		    				if(i%2==0 and a1!=0){
		    					s+=a;
		    					a1--;
		    					mp[a]=a1;
		    					if(b1==0){
		    						break;
		    					}
		    				}else
		    				if(i%2==1 and b1!=0){
		    					s+=b;
		    					b1--;
	    						mp[b]=b1;

		    				}
		    			}
		    			
    				}
    			}
    			// cout<<c.first<<" "<<c.second<<endl;
    			count++;
    		}
    		for(auto c: mp){
    			string s2="";
    			// cout<<c.first<<" "<<c.second<<endl;
    			if(c.second>=1){
    				s2.resize(c.second , c.first);
    			}
    			s+=s2;
    		}
    	}
    	cout<<s<<endl;
    }
    return 0;
}