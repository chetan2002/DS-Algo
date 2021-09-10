#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class disjointSetUnion {
public:
	vector<ll> findTheParent;
	vector<ll> findTheRank;

	disjointSetUnion(ll n) {
		findTheParent.resize(n+1);
		findTheRank.resize(n+1);
		for (ll iterator1 = 0; iterator1 <= n; iterator1++) {
			findTheParent[iterator1] = iterator1;
			findTheRank[iterator1] = 1;
		}
	}

	ll find(ll a) {
		if (findTheParent[a] == a) {
			return a;
		}
		ll x = find(findTheParent[a]);
		return findTheParent[a] = x;
		
	}

	bool findTheUnion(ll a, ll b) {
		ll pa = find(a);
		ll pb = find(b);
		if (pa == pb) {
			return 0;
		}
		if (findTheRank[pa] > findTheRank[pb]) {
			findTheParent[pb] = pa;
		} else if (findTheRank[pb] > findTheRank[pa]) {
			findTheParent[pa] = pb;
		} else {
			findTheParent[pa] = pb;
			findTheRank[pb]++;
		}
		return 1;
	}

};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll m1 , m2;cin>>m1>>m2;
    vector<vector<ll>> graphOne(n+1 ,vector<ll>(n+1,0)) ,graphTwo(n+1 ,vector<ll>(n+1,0));

    disjointSetUnion dsu1(n+1) ;
    disjointSetUnion dsu2(n+1);

    for (ll iterator1 = 0; iterator1 < m1; iterator1++) {
		ll u;
		ll v;
		cin>>u>>v;
		graphOne[u][v] = 1;
		dsu1.findTheUnion(u, v);
	}
	for (ll iterator1 = 0; iterator1 < m2; iterator1++) {
		ll u;
		ll v;
		cin>>u>>v;
		graphTwo[u][v] = 1;
		dsu2.findTheUnion(u, v);
	}

	vector<string> answer;
	for (ll iterator1 = 1; iterator1 <= n; iterator1++) 
		for (ll iterator2 = iterator1 + 1; iterator2 <= n; iterator2++) 
			if (graphOne[iterator1][iterator2] == 0)
				if(graphTwo[iterator1][iterator2] == 0)
					if( dsu1.find(iterator1)!=dsu1.find(iterator2))  
						if(dsu2.find(iterator1)!=dsu2.find(iterator2)){
							string ans="";
							dsu1.findTheUnion(iterator1, iterator2);
							dsu2.findTheUnion(iterator1, iterator2);
							ans += to_string(iterator1) + " ";
							ans += to_string(iterator2);
							answer.push_back(ans);
						} 
				
		
	
	cout<<answer.size()<<endl;
	for(auto c: answer){
		cout<<c<<endl;
	}

    return 0;
}