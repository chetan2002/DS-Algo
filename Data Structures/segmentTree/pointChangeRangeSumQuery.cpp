#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int a[10005]={0} , seg[4*10005]={0};

void build(int ind , int low , int high) {
	if (low == high) {
		seg[ind] = a[low];
		return;
	}

	int mid = (low + high ) / 2;
	build(ind*2 + 1 , low , mid);
	build(ind*2 + 2 , mid+1 , high);

	seg[ind] = seg[2*ind + 1]+seg[2*ind +2 ];
}

int pointQuery(int ind , int low ,int high , int l , int r) {
	if(low >= l and high <=r) {
		return seg[ind];
	}

	if (high < l || low > r) return 0;

	int mid = (low+high) /2;
	int left = pointQuery(2*ind +1 , low , mid , l , r);
	int right = pointQuery(2*ind +2 , mid+1 , high , l , r);
	return left + right;
}

void pointUpdate(int ind , int low , int high , int node , int val) {
	if (low == high) {
		seg[ind] += val;
		a[low] += val;
	}
	else {

		int mid = (high+low)/2;

		if(node<=mid and node>=low) {
			pointUpdate(2*ind + 1 , low , mid , node , val);
		}else{
			pointUpdate(2*ind + 2 , mid+1 , high , node , val);
		}

		seg[ind] = seg[2*ind+1] + seg[2*ind+2];	
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int n , q;
 	cin>>n>>q;
 	for(int i=0;i<n;i++) {
 		cin >>a[i];
 	}   

 	build(0 , 0 , n-1);

 	//0 a b to query
 	//1 a b add b to pos[a]

 	while(q--){
 		int i , a , b;
 		cin>>i>>a>>b;
 		if(i==0){
 			cout<<pointQuery(0 , 0 , n-1 , a , b)<<endl;;
 		}else{
 			pointUpdate(0 , 0 , n-1 , a , b);
 		}
 	}
    return 0;
}