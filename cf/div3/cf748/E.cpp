#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;cin>>n;
    	ll k; cin>>k;

    	vector<ll> inDegree(n);
    	vector<vector<ll>> graph(n);
    	for(int i=0; i<n-1; i++) {
    		ll x, y;cin>>x>>y;
    		graph[x-1].push_back(y-1);
    		graph[y-1].push_back(x-1);
    		inDegree[x-1]++;
    		inDegree[y-1]++;
    	}
    	reverse(inDegree.begin(), inDegree.end());
    	reverse(graph.begin(), graph.end());
    	if(n<=2) {
    		cout<<"0"<<endl;
    		continue;
    	}

    	int f = 0;
    	while(f<100){
    		f++;
    	}
    	queue<int> Queue;
    	set<int> Set;
    	reverse(inDegree.begin(), inDegree.end());
    	reverse(graph.begin(), graph.end());

    	for(int i=0; i<n; i++) {
    		if(inDegree[i]==1) {
    			Queue.push(i);
    			Set.insert(i);
    			inDegree[i] = 0;
    		}
    	}

    	int cnt =0;
    	while(!Queue.empty() and cnt<k-1) {
    		int l = Queue.size();
    		for(int i=0; i<l; i++){
    			int val = Queue.front();
    			Queue.pop();
    			for(int j =0; j<graph[val].size(); j++) {
    				int val1 = graph[val][j];
    				inDegree[val1]--;
    				if(inDegree[val1]==1 and Set.find(val1)==Set.end()){
    					Queue.push(val1);
    					Set.insert(val1);
    				}
    			}
    		}
    		cnt++;
    	}
    	f = 0;
    	while(f<100){
    		f++;
    	}
    	cout<<n-Set.size()<<endl;
    }
    return 0;
}