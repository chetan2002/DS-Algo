// https://codeforces.com/problemset/problem/570/C

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
 	int count = 0 , lastIns = -1; 	
 	int answer = 0;
 	for(int i=1;i<=n;i++) {
 		if(s[i-1]=='.') {
 			if(lastIns+count==i) {
 				count++;
 			}else{
 				lastIns = i;
 				count = 1;
 			}
 		}else {
 			if(count!=0) {
 				answer += (count-1);
 				count =0 ;
 			}
 		}
 	}
 	if(count!=0) {
		answer += (count-1);		
	}

 	while(q--) {
 		ll pos ;
 		char c;
 		cin>>pos>>c;
 		pos--;
 		if(s[pos]=='.' and c=='.') {
 			cout<<answer<<endl;
 			continue;
 		}
 		if(s[pos]!='.' and c!='.') {
 			cout<<answer<<endl;
 			continue;
 		}

 		if(pos!=0) {
 			if(c=='.' and s[pos-1]=='.') {
 				answer++;
 			}
 			if(c!='.' and s[pos-1]=='.') {
 				answer--;
 			}
 		}
 		if(pos!=n-1) {
 			if(c=='.' and s[pos+1]=='.') {
 				answer++;
 			}
 			if(c!='.' and s[pos+1]=='.') {
 				answer--;
 			}
 		}
 		s[pos] = c;
 		cout<<answer<<endl;
 	}

    return 0;
}