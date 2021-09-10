#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ll n , k;
    cin>>n>>k;
    vector<double> v;
    for(ll i=0;i<n;i++){
        double val;
        cin>>val;
        v.push_back(val);
    }
    double maxi = 0;
    cout.precision(15);
    for(int i=0;i<n;i++){
        double sum =0 ;
        if(i+k>n){
            break;
        }
        for(int j=i;j<n;j++){
            sum+=v[j];
            if(j>=i+k-1){
                double ans = sum/(j-i+1);
                maxi= max(ans , maxi);
            }
            
        }
    }   
    cout<<maxi<<endl;
    return 0;
}