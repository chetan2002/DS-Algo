#include<bits/stdc++.h>
using namespace std;
#define ll long long int
long double scale = 1e+6;

long double findAns(ll c, ll m , ll p , ll v){

	long double ans = (p/scale);
	if(c!=0){
		if(c>v){
			if(m>0){
				ans+= (c/scale)*(1+findAns(c-v,m+(v/2),p+(v/2),v));
			}else{
				ans+= (c/scale)*(1+findAns(c-v, m , p+v,v));
			}
		}else{
			if(m>0){
				ans+= (c/scale)*(1+findAns(0,m+(c/2),p+(c/2),v));
			}else{
				ans+= (c/scale)*(1+findAns(0, m , p+c,v));
			}
		}
	}

	if(m!=0){
		if(m>v){
			if(c>0){
				ans+= (m/scale)*(1+findAns(c+(v/2),m-v,p+(v/2),v));
			}else{
				ans+= (m/scale)*(1+findAns(c, m-v , p+v,v ));
			}
		}else{
			if(c>0){
				ans+= (m/scale)*(1+findAns(c+(m/2),0,p+(m/2),v));
			}else{
				ans+= (m/scale)*(1+findAns(c, 0 , p+m,v ));
			}
		}
	}
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	long double c1 , m1 , p1, v1;
    	cin>>c1>>m1>>p1>>v1;
    	ll c = round(c1*scale);
    	ll m = round(m1*scale);
    	ll p = round(p1*scale);
    	ll v = round(v1*scale);
    	long double ans= findAns(c,m,p,v);
    	cout<<setprecision(12)<<ans<<endl;
    }
    return 0;
}