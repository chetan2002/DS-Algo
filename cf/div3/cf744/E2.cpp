#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
  
// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
  

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	deque<ll> v;
        ordered_set s;
        ll count =0;
    	for(int i=0;i<n;i++) {
    		ll val;
    		cin>>val;

            ll val1 = 0, val2 = 0;
            val1 = s.size()- *s.find_by_order(val);
            val2 = s.find_by_order(val);
            count += min(val2, val1);
            s.insert(val);
    	}
    	int arr[n];
    	int  i=0;
    	for(auto c: v) {
    		// cout<<c<<" ";
    		arr[i++] = c;
    	}
    	cout<<getInvCount(arr, n)<<endl;
    }
    return 0;
}