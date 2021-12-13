#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool comp(vector<string> &a, vector<string> &b) {
	return stoi(a[1])<stoi(b[1]);
}
int storeItemsTracker2(vector<string> pricelist, vector<string> logs) {
	unordered_map<string, int> mp;
	for(auto c: pricelist) {
		string s1 = "";
		string s2 = "";
		bool wait = false;
		for(auto a: c) {
			if (a==':') {
				wait = true;
				continue;
			}
			if(wait) {
				s2+=a;
			}else {
				s1+=a;
			}
		}
		mp[s1] = stoi(s2);
	}
	unordered_map<string, int> invent;
	vector<vector<string>> array;
	for(auto c: logs) {
		string s = "";
		vector<string> divv;
		for(auto a: c) {
			if(a=="," || isspace(a)) {
				if(s!="") {
					divv.push_back(s);
					s = "";
				}
				continue;
			}
			s += a;
		}
		divv.push_back(s);
		array.push_back(divv);
	}
	sort(array.begin(), array.end(), comp);
	int discount = 0;
	int discountTime = -1;
	int sum =0 ;
	for(auto c: array) {
		if(stoi(c[1])<discountTime) {
			discount =0;
		}
		if(c[0] == "supply") {
			invent[stoi(c[2])] = stoi(c[3]);
		}else
		if(c[0]=="sell") {
			if(invent(c[2])>=)
			sum += 
		}
	}
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;cin>>n>>m;
    vector<string> pricelist;
    vector<string> logs;
    for(int i=0; i<n; i++) {
    	string s;cin>>s;
    	pricelist.push_back(s);
    }
    for(int j=0; j<m; j++) {
    	string s; cin>>s;
    	logs.push_back(s);
    }
    cout<<storeItemsTracker2(pricelist, logs)<<endl;
    return 0;
}