#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll maxVal = 20;
bool solve1(ll a, ll b) {
	ll ans = b;
    if(b==1 and a!=1 ){
        return false;
        
    }
    if(a == 1) {
        return true;
    }
    if(__gcd(a,b) == 1) {
        return false;
    }
    ll value = 1000000000000ll;
    bool isTrue = false;
    while(ans < value) {
        if(ans%a ==0 ) {
            isTrue = true;
            break;
        }
        ans *=b;
        cout<<ans<<" ";

    }
    return isTrue;
}
bool solve2(ll a, ll b) {
    ll p = b;
        
    while(p < a){
        p *= b;
    }
    
    while(__gcd(p,a) != 1){
        a /= __gcd(p,a);
    }
    
    if(a==1) return true;

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // while( true ) {
        ll a, b;
        cin>>a>>b;
    	bool ans1 = solve1(a, b);
    	bool ans2 = solve2(a,b);

    	if(ans2 == ans1) {
    		cout<<a<<" "<<b<<endl;
    		cout<<"OK"<<endl;
    	}else {
    		cout<<a<<" "<<b<<endl;
    		cout<<"WRONG ANS"<<endl;
    		cout<<"GOT: "<<ans1<<endl;
    		cout<<"EXP: "<<ans2<<endl;
    		// break;
    	}

    	cout<<endl;
    // }

    return 0;
}