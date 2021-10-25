Replacement2.cpp// https://codeforces.com/problemset/problem/570/C

#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	int n , q;
 	cin>>n>>q;
 	string s;
 	cin>>s;
 	map<int,int> mp;
 	int count = 0 , lastIns = -1;
 	set<int> mySet;
 	mySet.insert(lastIns);
 	int answer = 0;
 	for(int i=1;i<=n;i++) {
 		if(s[i-1]=='.') {
 			if(lastIns+count==i) {
 				count++;
 			}else{
 				lastIns = i;
 				count = 1;
 				mySet.insert(i);
 			}
 		}else {
 			if(count!=0) {
 				mp[lastIns] = count;
 				answer += (count-1);
 				count =0 ;
 			}
 		}
 	}
 	if(count!=0) {
		mp[lastIns] = count;
		answer += (count-1);		
	}

 	while(q--) {
 		ll pos ;
 		char c;
 		cin>>pos>>c;
 		if(s[pos-1]=='.' and c=='.') {
 			cout<<answer<<endl;
 			continue;
 		}
 		if(s[pos-1]!='.' and c!='.') {
 			cout<<answer<<endl;
 			continue;
 		}
 		auto it = mySet.lower_bound(pos);
 		if(it!=mySet.end() and *it == pos) {
 			if(c != '.' ) {
 				int value = mp[pos];
 				mp.erase(pos);
 				mySet.erase(pos);
 				if(value != 1){
 					answer--; 				
	 				mp[pos+1] = value-1;
	 				mySet.insert(pos+1);
 				}
 			} 
 			cout<<answer<<endl;
 			continue;
 		}
 		if(it!=mySet.end() and *it == pos+1) {
 			if(c=='.' ) {
 				auto k = it;
 				k--;
 				int position = 
 				int value = mp[pos+1];
 				mp.erase(pos+1);
 				mySet.erase(pos+1);
 				answer++; 				
 				
 				mp[pos] = value+1;
 				mySet.insert(pos);
 			}
 			cout<<answer<<endl;
 			continue;
 		}
 		it--;
 		if(*it==-1) {
 			if(c=='.') {
 				mySet.insert(pos);
 				mp[pos] = 1;
 			}
 			cout<<answer<<endl;
 			continue;
 		}
 		int position = *it;
 		int value = mp[position];
 		if(value+position >= pos){
 			if(c!='.') {
 				mp[position] = pos-position;
 				answer-=2; 				
 				mp[pos+1] = value-mp[position]-1;
 				mySet.insert(pos+1);
 			}
 		}
 		cout<<answer<<endl;
 	}

    return 0;
}