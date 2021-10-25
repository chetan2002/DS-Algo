//LCS
// x: a b  c d g h 
// y: a b e d f h r 

// solution 
// base 
// if (n == 0 || m == 0)  return 0;
// recursive
// if x[n] == y[m] : check on n-1 and m-1
// else : check on (n-1, m ) and (n, m-1);


#include<bits/stdc++.h>
using namespace std;
#define ll long long int


// recursive
int dp[10000][10000];
int lcs(string x , string y , int n , int m) {
	if(n==0 || m==0) {
		return 0;
	}
	if(dp[n][m]!=-1) {
		return dp[n][m];
	}
	int value =0;
	if(x[n-1] == y[m-1]) {
		value =  1 + lcs(x, y , n-1 , m-1) ;
	}else {
		value = max(lcs(x,y, n-1, m), lcs(x, y , n, m-1));
	}

	return dp[n][m] = value;
}


// bottom up
int lcsBottomUp(string x , string y) {
	int n = x.length() , m = y.length();
	int mem[n+1][m+1];
	memset(mem, 0, sizeof(mem));
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(x[i-1]==y[j-1]) {
				mem[i][j] = 1 + mem[i-1][j-1];
			}else{
				mem[i][j] = max(mem[i][j-1], mem[i-1][j]);
			}
		}
	}
	return mem[n][m];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	string x , y;
 	cin>>x>>y;
 	memset(dp, -1, sizeof(dp));
 	cout<<lcs(x, y , x.length(), y.length())<<endl;;
 	cout<<lcsBottomUp(x,y)<<endl;
    return 0;
}