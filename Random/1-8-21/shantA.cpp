#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int compare(const void *p , const void *q){
	int x = *(const int *)p;
	int y = *(const int *)q;

	if(x<y){
		return -1;
	}else
	if(x>y){
		return 1;
	}
	return 0;
}

bool tryMid(int *arr , int n , int c , int gap){
	int put = 1 , lastInd = arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]-lastInd >=gap){
			lastInd = arr[i];
			put++;
		}

		if(put>=c){
			break;
		}
	}

	if(put>=c){
		return true;
	}
	return false;
}
int LargestMinimumDistance(int *arr , int n , int c){
	if(n==0){
		return 0;
	}
	qsort(arr , n , sizeof(*arr) , compare);
	int s =0 , e = INT_MAX;
	int ans = 0;
	while(s<=e){
		int mid = s + (e-s)/2;
		if(tryMid(arr , n , c , mid)){
			s = mid+1;
			ans = max(ans , mid);
		}else{
			e = mid-1;
		}
	}
	return ans;
}
int main(){
    int n , c;
    cin>>n>>c;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }   
    // sort(arr , arr+n);
    int result = LargestMinimumDistance(arr , n , c);
    cout<<result<<endl;
    return 0;
}