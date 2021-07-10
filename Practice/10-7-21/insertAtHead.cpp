#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	list<ll> v;
 	int n;
 	cin>>n;
 	for(int i=0;i<n;i++){
 		ll val;
 		cin>>val;
 		v.push_front(val);
 	}   

 	for(auto c: v){

 		cout<<c<<endl;
 	}
    return 0;
}