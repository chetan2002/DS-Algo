#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> v;

bool check(int a) {
	int i=0, j=v.size()-1;
	while(i<j) {
		while(i<j and v[j]==a) {
			j--;
		}
		while(i<j and v[i]==a) {
			i++;
		}
		if(i<j and v[i]!=v[j]) {
			return false;
		}
		i++, j--;
	}
	return true;
}
bool answer() {
	if(v.size()==1) {
		return true;
	}
	int i=0, j=v.size()-1;
	int val1 = -1, val2 = -1;
	while(i<j) {
		if(v[i]!=v[j]) {
			val1 = v[i];
			val2 = v[j];
			break;
		}
		i++, j--;
	}

	if(i>=j || val1 == -1) {
		return true;
	}
	return (check(val1) || check(val2));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;cin>>n;
    	v.clear();
    	v.resize(n);
    	for(auto &c: v) {
    		cin>>c;
    	}
    	if(answer()) {
    		cout<<"YES"<<endl;
    	}else{
    		cout<<"NO"<<endl;
    	}
    }
    return 0;
}