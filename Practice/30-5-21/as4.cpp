#include<bits/stdc++.h>
using namespace std;
#define ll long long int


bool cmp(pair<string,ll> p1 , pair<string,ll> p2){
	if(p1.second!=p2.second){
		return p1.second>p2.second;
	}
	return p1.first<p2.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;
 	cin>>n;

 	unordered_map<string , ll> mp;
 	for(int i=0;i<n;i++){
 		string s;
 		cin>>s;
 		mp[s]++;
 	}

 	vector<pair<string,int>> vp;
 	for(auto c: mp){
 		vp.push_back(c);
 	}

 	sort(vp.begin(),vp.end() , cmp);

 	cout<<vp.size()<<endl;
 	for(auto c: vp){
 		cout<<c.first<<endl;
 	}
    return 0;
}