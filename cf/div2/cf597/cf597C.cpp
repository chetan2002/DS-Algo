#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1000000007;

ll arr[100005];

ll findans(string &s , int i ){
	if(i==s.length()){
		return 1;
	}
	if(arr[i]!=-1){
		return arr[i];
	}
	int ans = 0 ;
	if(i+1<s.length() and ((s[i]=='n' and s[i+1]=='n') or (s[i]=='u' and s[i+1]=='u'))){
		ans = findans( s, i+2);
	}
	ans = ans%mod;
	ans += findans(s , i+1);
	return arr[i] = ans%mod;
}
ll answer(string s){
	for(auto c: s){
		if(c=='m' or c=='w'){
			return 0;
		}
	}

	ll ans =findans(s , 0);
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	string s;
 	cin>>s;
 	memset(arr, -1 , sizeof(arr));
 	cout<<answer(s)<<endl;   

    return 0;
}