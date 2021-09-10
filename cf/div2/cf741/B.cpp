#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool prime[100001];

void seivePrime(ll n){
    memset(prime , true , sizeof(prime));

    for(int p = 2 ; p*p<=n ; p++){
        if(prime[p] == true){
            for(int i=p*p ; i<=n ; i+=p){
                prime[i] = false;
            }
        }
    }
}

bool checkF(string s1 , string s2){
    int i = 0 ;
    for(auto c: s2){
        if(c==s1[i]){
            i++;
        }
        if(i==s1.length()){
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    seivePrime(100000);
    while(t--){
        string ans = "";
        int n;cin>>n;
        string s;
        cin>>s;
        for(auto c: s){
            if(c=='1'){
                ans = "hello";
                break;
            }
        }
        if(ans!=""){
            cout<<1<<endl;
            cout<<1<<endl;
            continue;
        }
        for(int i=4;i<1000000;i++){
            if(prime[i]==false){
                string k = to_string(i);
                bool check= checkF(k , s);
                if(check){
                    ans = k;
                    break;
                }
            }
        }
        if(ans!=""){
             cout<<ans.length()<<endl;
            cout<<ans<<endl;
        }else{
            cout<<s.length()<<endl;
            cout<<s<<endl;
        }
    }
    return 0;
}