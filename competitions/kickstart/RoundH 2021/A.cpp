#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int value(char c) {
    return (int)(c-'a');
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    for(int l=1;l<=t;l++){
    	
        string s;cin>>s;
        string f; cin>>f;
        set<int> ff;
        for(auto c: f) {
            ff.insert(value(c));
        }
        int count =0;

        for(auto c: s) {
            auto a = ff.lower_bound(value(c));
            if(a==ff.end()) {
                count += min(abs(value('z')-value(c)+*(ff.begin())), abs(value(c)-*prev(a)));
            }else
            if(*a == value(c)) {
                continue;
            }else
            if(a == ff.begin()) {
                count += min(abs(*(a) - value(c)), abs(value('z')-*ff.rbegin())-value(c));
            }else{
                count += min(abs(*(a)-value(c)), abs(*prev(a)-value(c)));
            }
            // cout<<count<<endl;
        }
    	cout<<"Case #"<<l<<": "<<count<<endl;;

    }
    return 0;
}