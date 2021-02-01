#include<bits/stdc++.h>
using namespace std;
#define ll long long int


void printStockSpan(ll *arr ,ll n){

    stack<ll> s;
	vector<ll> v;
	v.push_back(1);
	s.push(0);

    for(ll i=1 ; i<n ;i++){
       
        while(!s.empty() && ( arr[s.top()] <= arr[i])){
            s.pop();
        }
        if(s.empty()){
			v.push_back(i+1);
        }else{
			v.push_back(i-s.top());
        }

        s.push(i);

    }
	
	for(auto c: v){
		cout<<c<<" ";
	}
}


int main(){
    ll n;;
    cin>>n;
    ll arr[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printStockSpan(arr , n);
    return 0;
}