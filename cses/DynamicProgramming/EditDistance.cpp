#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string s1, s2;
vector<vector<ll>> dp;
ll editDistance(ll a, ll b) {
	if(a==0 or b==0) {
		return a+b;
	}
	if(dp[a][b]!=-1) {
		return dp[a][b];
	}
	int value = 0;
	if(s1[a-1]==s2[b-1]) {
		value = editDistance(a-1, b-1);
	}else {
		value = 1 + min(editDistance(a-1, b), min(editDistance(a, b-1), editDistance(a-1, b-1)));
	}
	return dp[a][b]= value;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	cin>>s1>>s2;
 	dp.resize(s1.length()+1, vector<ll>(s2.length()+1, -1));
 	cout<<editDistance(s1.length(), s2.length())<<endl;
    return 0;
}