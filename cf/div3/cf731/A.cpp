#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll Ax , Ay , Bx , By , Cx , Cy;
    	cin>>Ax>>Ay>>Bx>>By>>Cx>>Cy;
    	ll ans = 0;
    	if(Ax==Bx){
    		if(Ax==Cx and ((By-Cy>0 and Cy-Ay>0) or (Cy-By>0 and Ay-Cy>0))){
    			ans+=abs(By-Ay)+2;
    		}else{
    			ans+=abs(By-Ay);
    		}
    	}else
    	if(Ay==By){
    		if(Ay==Cy and ((Bx-Cx>0 and Cx-Ax>0) or (Cx-Bx>0 and Ax-Cx>0))){
    			ans+=abs(Bx-Ax)+2;
    		}else{
    			ans+=abs(Bx-Ax);
    		}
    	}else{
    		ans+=abs(Bx-Ax) + abs(By-Ay);
    	}

    	cout<<ans<<endl;

    }
    return 0;
}