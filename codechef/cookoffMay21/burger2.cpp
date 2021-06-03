#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve2(ll x , ll y){
    ll ans =-1;
 if((y%x)==0){
        y/=x;
        for(int k=1;k<60;k++){
            ll val=y+k;
            if(val%2)continue;
            int cnt=__builtin_popcountll(val);
            if(cnt==k){
                int tmp=0;
                for(int i=1;i<=60;i++){
                    if(val&(1LL<<i))tmp+=i;
                }
                tmp+=k-1;
                ans=tmp;
                break;
            }
        }
    }
    return ans;   
    
}

ll solve(ll X , ll Y)
{
    
  m
}



int main()
{

    srand(time(0));
    while(true){
        ll X , Y;
        X = rand()%10;
        Y = rand()%100;

        ll ans1 = solve(X ,Y);
        ll ans2 = solve2(X, Y);
        if(ans1==ans2){
            cout<<"OK"<<endl;
        }else{
            cout<<"FAILED"<<endl;
            cout<<X<<" "<<Y<<endl;
            break;
        }
    }
    return 0;
}