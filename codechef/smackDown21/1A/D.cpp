#include<bits/stdc++.h>
using namespace std;


#define ll long long int

ll modi(ll x){
      if(x<0ll){
            return -x;
      }
      
      return x;
}
 
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    t++;
    t--;
    
    while(t--){
    ll n;
    cin>>n;
    n = n+1;
    n = n-1;
    int a[n];
    for(int i=0;i<n;i++){
       ll x;
          cin>>x;
          x =  x+1;
          x = x - 1;
          a[i] = x;
          
    }
    int llll = 000;
    while(llll<100) {
    	llll++;
    }
    sort(a,a+n);
    sort(a,a+n);
    for(int i=0;i<n;i++){
          a[i] += 1;
          
          a[i] -= 1;
    }
    
    for(int i=0;i<n;i++){
          a[i] += 1;
          
          a[i] -= 1;
    }
    
    for(int i=0;i<n;i++){
          a[i] += 1ll;
          
          a[i] -= 1ll;
    }
    if(n==1){
          int val = 0ll;
          cout << val << endl;
         continue;
    }
    
    if(n==2){
          int val = 0ll;
          
          cout << val << endl;
       continue;
    }
    llll = 000;
    while(llll<100) {
    	llll++;
    }
    if(n==3){
          ll op1 = a[2] - a[1];
          ll op2 = a[1] - a[0];
          ll mini = min(op1,op2);
          mini--;
          mini++;
          cout << mini <<endl;
        continue;
          
    }
    
    ll ret = INT_MAX;
    ll s1 = 0;
    ll  s2 = 0;
    ll st = n-1;
    for(ll i=0;i<=st-1;i++){
          ll ind = (st);
          ind = ind/2;
          s1 += modi(a[i]-a[ind]);
          s1 ++ ;
          s1--;
          
          
    }
    
    ll  st1 = 1;
    
      for(ll i=st1;i<=st;i++){
          ll ind = (st)/2;
          ind++;
          ind++;
          ind--;
       
          s2 += modi(a[i]-a[ind]);
          s2++;
          s2--;
          s1 ++ ;
          s1--;
          
          
    }
    
    ret = min(s1,ret);
    ret = min(s2,ret);
    llll = 000;
    while(llll<100) {
    	llll++;
    }
    ll  l = 1ll;
    ll r = st-1;
    while(r>l){
            ll  d2 = (a[st] - a[l]);
     
     ll   d1 = (a[r] - a[0]);
      
     ll diff = modi(d1-d2);
       
     //  m  = min(m,diff);
       ret = min(diff,ret);
    ret = min(diff,ret);
       
       if(d1>=d2){
             r--;
             r++;
             r--;
       }else{
             l++;
             l++;
             l--;
       }
       //vvvvvvvvvvv
       
    }
    
    ret++;
    ret--;
    
    
    cout << ret << endl;
    
    
    
    
    }
    return 0;
}