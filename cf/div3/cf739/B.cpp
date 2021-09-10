#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll a, b , c;cin>>a>>b>>c;
    	a-- , b--  , c--;
    	int diff = abs(a-b);
    	int circleSize = diff*2;

    	if(c>=circleSize){
    		cout<<"-1"<<endl;
    		continue;

    	}
    	if(a>=circleSize || b>=circleSize){
    		cout<<"-1"<<endl;
    		continue;
    	}
    	int part = (c+diff)%circleSize ;
    	if(part==a || part==b){
    		cout<<"-1"<<endl;
    		continue;
    	}
    	cout<<part+1<<endl;
    }
    return 0;
}