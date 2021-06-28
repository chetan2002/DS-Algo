#include<bits/stdc++.h>
using namespace std;

string solve(int n , string s , string a){
	string R="";
	string G="";
	string B="";

	for(int i=0;i<n;i++){
		if(s[i]=='R'){
			R+=a[i];
		}
		if(s[i]=='G'){
			G+=a[i];
		}
		if(s[i]=='B'){
			B+=a[i];
		}
	}       

	sort(R.begin(),R.end(),greater<char>());
	sort(G.begin(),G.end(),greater<char>());
	sort(B.begin(),B.end(),greater<char>());

	int i=0,j=0,k=0;

	string answer = "";
	for(auto c: s){
		if(c=='R'){
			answer+=R[i++];
		}else
		if(c=='G'){
			answer+=G[j++];
		}else{
			answer+=B[k++];
		}
	}
	return answer;
}


int main(){
	
	int n;
	cin>>n;

	string col , num;
	cin>>col>>num;

	string answer = solve(n , col , num);
	cout<<answer<<endl;

    return 0;
}