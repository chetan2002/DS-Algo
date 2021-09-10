//https://www.spoj.com/problems/BRDGHRD/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool comp(pair<int,int> p1 , pair<int,int> p2){
	if(p1.second==p2.second){
		return p1.first<p2.first;
	}
	return p1.second<p2.second;
}

int answer(vector<pair<int,int>> vp){
	int n = vp.size();
	vector<int> dp(n+1);
	int count = 0;
	for(int i=0;i<n;i++){
		int s=0 , e = count;
		while(s<e){
			int mid = s+(e-s)/2;
			if(dp[mid]<=vp[i].first){
				s = mid+1;
			}else{
				e = mid;
			}
		}

		dp[s] = vp[i].first;
		if(s==count) count++;
	}
	return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	vector<pair<int,int>> vp(n);
    	for(auto &c:vp){
    		cin>>c.first;
    	}
    	for(auto &c: vp){
    		cin>>c.second;
    	}
    	sort(vp.begin(), vp.end() , comp);
    	// for(auto c: vp){
    	// 	cout<<c.first<<" "<<c.second<<endl;
    	// }
    	cout<<answer(vp)<<endl;
    }
    return 0;
}