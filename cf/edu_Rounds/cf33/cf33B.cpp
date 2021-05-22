#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n;
 	cin>>n;

 	vector<ll> v;
 	ll num = 1;
 	v.push_back(num);
 	while(num<=n){
 		num = num<<1;
 		int val = log2(num);
 		num = (1<<(val+1))+num;
 		v.push_back(num);
 	}   
 	ll greatest = 1;
 	for(auto c: v){
 		if(n%c==0){
 			greatest = c;
 		}
 	}
 	cout<<greatest<<endl;
    return 0;
}