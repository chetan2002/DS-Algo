#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<int>> v(7,vector<int>(7,0));
void print(){
	for(auto c: v){
		for(auto a: c){
			cout<<a<<" ";
		}
		cout<<endl;
	}
}
void possible(string s, int i ,int n ,int m, int &count){
	
	if(i==s.length()){
		count++;
		return;
	}
	if(n>=7 || m>=7 || n<0 || m<0){
		return ;
	}
	if(v[n][m]==1){
		return;
	}
	v[n][m] = 1;
	// cout<<"Working"<<" "<<i<<" "<<m<<" "<<n<<" "<<count<<endl;
	// print();
	if(s[i]=='?'){
			possible(s,i+1,n-1,m,count);
			possible(s,i+1,n+1,m,count);
			possible(s,i+1,n,m-1,count);
			possible(s,i+1,n,m+1,count);
	}else{
		if(s[i]=='U'){
			possible(s,i+1,n-1,m,count);
		}else
		if(s[i]=='D'){
			possible(s,i+1,n+1,m,count);
		}else
		if(s[i]=='L'){
			possible(s,i+1,n,m-1,count);
		}else
		if(s[i]=='R'){
			possible(s,i+1,n,m+1,count);
		}else{
			return;
		}
	}
	v[n][m] = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	string s;
 	cin>>s;
 	int count = 0;   
 	possible(s,0,0,0,count);
 	cout<<count<<endl;
    return 0;
}