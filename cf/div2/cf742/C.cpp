#include<bits/stdc++.h>
using namespace std;
#define ll long long int


ll answer(string n){
	int ans1 = 0 , ans2 = 0;
	for(int i=0;i<n.length();i+=2){
		ans1 = ans1*10 + (n[i]-'0');
	}
	for(int i=1;i<n.length();i+=2){
		ans2 = ans2*10 + (n[i]-'0');
	}
	return (ans1+1)*(ans2+1) - 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	string n;cin>>n;
    	cout<<answer(n)<<endl;
    }
    return 0;
}