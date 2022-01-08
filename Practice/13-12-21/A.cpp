#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	vector<pair<int,int>> vp(10);
 	int i=0;
 	unordered_map<int, int> mp;
 	for(auto &c: vp) {
 		c.first=i;
 		c.second = i+2;
 		mp[c.first] = c.second;
 		i++;
 	}

 	auto it = vp.begin();
 	while(it!=vp.end()) {
 		cout<<it->first<<" ";
 		cout<<(*it).second<<endl;
 		it++;
 	}
 	auto it2 = mp.begin();
 	while(it2!=mp.end()) {
 		cout<<(*it2).first<<" "<<(*it2).second<<endl;
 		it2++;
 	}
    return 0;
}

