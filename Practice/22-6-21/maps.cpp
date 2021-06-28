#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class freq{
public:
	int fre;
	string val;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	map<ll , freq> mp;
 	ll n;
 	cin>>n;
 	for(int i=0;i<n;i++){
 		ll val1 , val2;
 		cin>>val1>>val2;
 		freq f1;
 		f1.fre = val2;
 		f1.val = to_string(val1);
 		mp.insert({val1,f1});
 	}
 	if(mp.find(3)!=mp.end()){
 		cout<<mp[3].fre<<" "<<mp[3].val<<endl;
 	}
 	
 	for(auto c: mp){
 		cout<<c.first<<" "<<c.second.fre<<" "<<c.second.val<<endl;
 	}
    return 0;
}