#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    for(int l=1;l<=t;l++){
        ll k;
        cin>>k;
        
        vector<vector<ll>> v(k, vector<ll>(4));
        vector<int> xx;
        vector<int> yy;
        for(auto &c: v) {
            for(int i=0; i<4; i++) {
                if(i%2==0) {
                    cin>>c[i];
                    xx.push_back(c[i]);
                }else{
                    cin>>c[i];
                    yy.push_back(c[i]);
                }
            }
        }
        sort(xx.begin(), xx.end());
        sort(yy.begin(), yy.end());
     
        ll xmin = xx[(xx.size()-1)/2];
        ll ymin = yy[(yy.size()-1)/2];

        cout<<"Case #"<<l<<": "<<xmin<<" "<<ymin<<endl;;

    }
    return 0;
}