#include<bits/stdc++.h>
using namespace std;
#define ll long long int


bool checkPal(string s){
	int l = s.length();
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
			return false;
		}
	}
	return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n , m ;
 	cin>>n>>m;

 	vector<string> v(n);
 	for(int i=0;i<n;i++){
 		cin>>v[i];
 	}

 	vector<int> used(n , 0);

 	string palindrome = "";
 	unordered_map<string,string> mp;
 	for(int i=0;i<n;i++){
 		if(used[i]==0){
 			string rev = v[i];
 			reverse(rev.begin(),rev.end());

 			for(int j=i+1;j<n;j++){
 				if(used[j]==0){
 					if(rev == v[j]){
 						used[i] = 1;
 						used[j] = 1;
 						mp[v[i]] = v[j];
 					}
 				}
 			}

 			if(used[i]==0){
 				bool isPal= checkPal(v[i]);
 				if(isPal){palindrome = v[i];used[i]=1;}
 			}
  		}
 	}


 	
 	string answer = "";
		
	stack<string> s;
	for(auto c: mp){
		answer+=c.first;
		s.push(c.second);
	} 		

	answer+=palindrome;
	while(!s.empty()){
		answer+=s.top();
		s.pop();
	}

	cout<<answer.length()<<endl;
	cout<<answer<<endl;
    return 0;
}