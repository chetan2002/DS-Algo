#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll ini, n;
    	cin>>ini>>n;
    	ll res = ini;
    	ll moves = n%4;

    	if(moves == 1) {
    		if (ini %2 == 0) {
    			res -= n;
    		}else {
    			res +=n;
    		}
    	}else if (moves == 2) {
    		if(ini %2 == 0) {
    			res++;
    		}else{
    			res--;
    		}
    	}else if(moves == 3){
    		if(ini %2 ==0) {
    			res += n+1;
    		} else {
    			res = res-n-1;
    		}
    	}

    	cout<<res<<endl;

    }
    return 0;
}