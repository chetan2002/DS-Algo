#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int a[10005] , seg[10005*4] , lazy[10005*4];

void build(int ind , int low , int high){
	if (low == high) {
		seg[ind] = a[low];
		return;
	}
	int mid = (low+high)/2;
	build(ind*2 + 1 , low , mid);
	build(ind*2 + 2 , mid+1 , high);

	seg[ind] = seg[2*ind+1] + seg[ind*2 + 2];
}

void rangeUpdate(int ind , int low , int high , int l , int r , int val) {
	if(lazy[ind]!=0) {
		seg[ind] += (high-low+1) * lazy[ind];
		if(low != high) {
			lazy[2*ind + 1] += lazy[ind];
			lazy[2*ind + 2] += lazy[ind];
		}
		lazy[ind]=0;
	}

	if(r<low || l>high || low>high) return;

	if(low>=l and high<=r) {
		seg[ind] += (high - low + 1)*val;
		if(low!=high) {
			lazy[2*ind + 1] += lazy[ind];
			lazy[2*ind + 2] += lazy[ind];
		}
		return;
	}

	int mid = (low+high)/2;
	rangeUpdate(2*ind+1 , low , mid , l , r , val);
	rangeUpdate(2*ind+2 , mid+1 , high , l , r , val);
	seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

int querySumLazy(int ind , int low , int high , int l , int r) {
	if(lazy[ind] !=0) {
		seg[ind] += (high-low+1)*lazy[ind];
		if(low!=high) {
			lazy[2*ind+1] += lazy[ind];
			lazy[2*ind+2] += lazy[ind];
		}
		lazy[ind] = 0;
	}

	if(r<low || l>high || low>high ) return 0;
	if(low>=l and high <= r) {
		return seg[ind];
	}
	int mid = (low+high)/2;
	int left = querySumLazy(2*ind+1, low , mid , l , r );
	int right = querySumLazy(2*ind + 2 , mid+1 , high , l ,r );
	return left + right;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    build(0 , 0 , n-1);

    // 0 a b query range a-b
    //1 a b c add range a-b value c
    while(q--) {
    	int i;
    	cin>>i;
    	if(i==0){
    		int a , b;
    		cin>>a>>b;
    		cout<<querySumLazy(0,0,n-1,a,b)<<endl;
    	}else {
    		int a , b , c;
    		cin>>a>>b>>c;
    		rangeUpdate(0,0,n-1,a,b,c);
    	}
    }
    return 0;
}