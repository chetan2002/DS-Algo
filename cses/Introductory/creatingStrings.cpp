#include<bits/stdc++.h>
using namespace std;
#define ll long long int
set<string> s;

void answer(string in){
	string f = in;
	s.insert(in);
	while(next_permutation(in.begin(),in.end())){
		if(in==f){
			break;
		}
		s.insert(in);
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	string in;
 	cin>>in;
 	s.clear();
 	sort(in.begin(),in.end());
 	answer(in);
 	cout<<s.size()<<endl;
 	for(auto c: s){
 		cout<<c<<endl;
 	}
    return 0;
}