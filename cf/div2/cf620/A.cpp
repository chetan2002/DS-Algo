#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	double x , y , a , b;
    	cin>>x>>y>>a>>b;
    	// x+ak = y-bk
    	double value = (y-x)/(b+a);

    	if(value-(int)value >0){
    		cout<<"-1"<<endl;
    	}else{
    		cout<<(int)value<<endl;
    	}

    }
    return 0;
}