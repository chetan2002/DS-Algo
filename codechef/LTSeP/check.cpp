#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll maxVal = 1e9;
bool solve1(ll a, ll b) {
	ll ans = b;
    if(b==1 and a!=1 ){
        return false;
        
    }
    if(a == 1) {
        return true;
    }
    // if(__gcd(a,b) == 1) {
    //     return false;
    // }
    ll value = 1000000000ll;
    bool isTrue = false;
    while(ans < value) {
        if(ans%a ==0 ) {
            isTrue = true;
            break;
        }
        ans *=b;
    }
    return isTrue;
}
bool solve2(ll a, ll b) {
	if(a%2==0){			
	    if(b%2){
	        // cout<<"NO\n";
	        return false;
	    }
	    while (a % 2 == 0)
	    {
	        a = a/2;
	    }
	}
	for (ll j = 3; j*j <= a; j = j + 2)
	{
	    while (a % j == 0)
	    {
	        if(b%j){
	            // cout<<"NO\n";
	            return false;
	        }
	        while(a%j==0){
	            a/=j;
	        }
	    }
	}
	if (a > 2)
	{
	    if(b%a){
	        // cout<<"NO\n";
	        return false;
	    }
	} 
	// cout<<"YES\n";
	return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(0));
    while( true ) {
    	ll a =1 + (rand() % maxVal);
    	ll b =1 + (rand() % maxVal);
    		cout<<a<<" "<<b<<endl;

    	bool ans1 = solve1(a, b);
		cout<<"GOT: "<<ans1<<endl;

    	bool ans2 = solve2(a,b);
		cout<<"EXP: "<<ans2<<endl;

    	if(ans2 == ans1) {
    		cout<<"OK"<<endl;
    	}else {
    		cout<<"WRONG ANSWER!!!"<<endl;
    		break;
    	}

    	cout<<endl;
    }

    return 0;
}