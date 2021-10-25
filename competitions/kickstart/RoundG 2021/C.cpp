#include<bits/stdc++.h>
using namespace std;
#define ll int
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


ll a[100005] , seg[4*100005];
void build(ll ind , ll low , ll high) {
	if (low == high) {
		seg[ind] = a[low];
		return;
	}

	ll mid = (low + high ) / 2;
	build(ind*2 + 1 , low , mid);
	build(ind*2 + 2 , mid+1 , high);

	seg[ind] = seg[2*ind + 1]+seg[2*ind +2 ];
}

ll pointQuery(ll ind , ll low ,ll high , ll l , ll r) {
	if(low >= l and high <=r) {
		return seg[ind];
	}

	if (high < l || low > r) return 0;

	ll mid = (low+high) /2;
	ll left = pointQuery(2*ind +1 , low , mid , l , r);
	ll right = pointQuery(2*ind +2 , mid+1 , high , l , r);
	return left + right;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    for(ll l=1;l<=t;l++){
        ll n, k;
        cin>>n>>k;


        for(ll i=0; i<n; i++) {
        	cin>>a[i];
        }

     	build(0 , 0 , n-1);
    //  	vector<vector<int>> v(n, vector<int>(n,0));
     	unordered_map<ll, vector<pair<ll,ll>>, custom_hash> mp;
     	for(ll p = 0; p<n; p++) {
			for(ll q=p; q<n; q++) {
				ll sum2 = pointQuery(0, 0, n-1, p, q);
				// cout<<"\t"<<sum2<<endl;
				// v[p][q] = sum2;
				if(sum2>=k) {
				    break;
				}
				mp[sum2].push_back({p,q});
			}
		}
     	ll mini = -1;
     	for(ll i=0; i<n; i++) {
     		for(ll j=i; j<n; j++) {
				ll sum1 = pointQuery(0, 0, n-1, i, j);
				if(sum1 == k) {
					if(mini == -1) {
						mini = j-i+1 ;
					}else{
						mini = min(mini, j-i+1);
					}
					break;
				}

				for(auto c: mp[k-sum1]) {
					if(c.first>j || c.second<i) {
						if(mini == -1) {
							mini = j-i+1 + c.second-c.first+1 ;
						}else{
							mini = min(mini,j-i+1 + c.second-c.first+1 );
						}
					}
				}
				
     		}
     	}
        cout<<"Case #"<<l<<": "<<mini<<endl;;

    }
    return 0;
}