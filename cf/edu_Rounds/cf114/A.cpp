#include<bits/stdc++.h>
using namespace std;
#define ll long long int


void print(string s, int o , int c, int n , int &count) {
	if(count == n) {
		return;
	}
	if(o==n and c==n) {
		cout<<s<<endl;
		count++;
		return;
	}

	if(c<n and c<o) {
		print(s+")", o , c+1, n, count);
	}
	if(o<n) {
		print(s+"(", o+1, c, n, count);
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;

    while(t--){
    	int n;
    	cin>>n;
    	int count =0 ;
    	print("", 0, 0, n, count);
    }
    return 0;
}