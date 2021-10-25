#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int check(string s, string a) {
	int count =0 , i =0;
	for(auto c: s) {
		if(i==2) {
			return count;
		}
		if(c==a[i]){
			i++;
			continue;
		}else{
			count++;
		}
	}
	return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	string s;
    	cin>>s;
    	reverse(s.begin(), s.end());
    	int mini= s.length();
    	mini = min(check(s, "52"), min(check(s, "57"), min(check(s, "05"), check(s, "00"))));
    	cout<<mini<<endl;
    }
    return 0;
}