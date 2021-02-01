#include<bits/stdc++.h>
using namespace std;

void printSeq(string s){
	if(s.length()==0){
		cout<<endl;
		return;
	}

	stack<int> st;
	for(int i=0;i<=s.length();i++){
		st.push(i+1);

		if(i==s.length() || s[i]=='I'){
			while(!st.empty()){
				cout<<st.top();
				st.pop();
			}
		}
	}
	cout<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		printSeq(s);
	}
	return 0;
}