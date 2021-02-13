#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_set<string> s;
        vector<string> v;
        for(int i=0 ;i<n;i++){
            string a ;cin>>a;
            s.insert(a);
            v.push_back(a);
        }
        ll count = 0;
        for(int i=0;i<n;i++){
            for(int j=0 ;j<n ; j++){
                string a = v[i];
                string b = v[j];
                swap(a[0] , b[0]);
                if(s.find(a)==s.end() && s.find(b)==s.end()){
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}