#include<bits/stdc++.h>
using namespace std;

void lexo(string s , string a , int n , vector<string> &v){
	if(a.length()==n){
		if(stoll(a)<=stoll(s)){
			v.push_back(a);
		}
		return;
	}
	if(a!="" and stoll(a)<=stoll(s)){
		v.push_back(a);
	}
	
	if(a.length()>0 and a[0]=='0'){
		return;
	}
	for(int i=0;i<=9;i++){
		lexo(s , a+to_string(i) , n , v);
	}
}

int main(){
	string s;
	cin>>s;
	if(s=="0"){
		cout<<s<<endl;
		return 0;
	}
	vector<string> v;
	int n = s.length();
	lexo(s , "" , n , v);
	for(auto c: v){
		cout<<c<<" "; 
	}
	return 0;
}
