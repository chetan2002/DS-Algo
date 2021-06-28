#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ansi_ ios_base::sync_with_stdio(false); cin.tie(NULL);
 
double solve1(lli n ,lli len ,lli* a){
 
   sort(a,a+n);
   
   lli ma=0;
   
   for(lli i=1;i<n;i++)
      ma=max(ma,a[i]-a[i-1]);
   
   double temp=ma/2.0;
   
   double tem=max(a[0],len-a[n-1]);
   double ans=max(tem,temp);
   return ans;
   
}

lli rez;
double solve2(lli n , lli l, lli* a){

    sort(a,a+n);
    rez = 2*max(a[0],l-a[n-1]);
    for (lli i = 0; i < n-1; i++)
        rez = max(rez, a[i+1]-a[i]);
    double ans = rez/2.0;

    return ans;
}
 
int main() {
 
    ansi_
    srand(time(0));

    while(true){
      lli n,len;
      n = rand()%100;
      len =1+ rand()%200;
      
      lli a[n];
      
      for(lli i=0;i<n;i++)
         a[i] = rand()%len;
      
      double ans1 = solve1(n , len , a);
      double ans2 = solve2(n , len , a);
      if(ans1==ans2){
         cout<<"OK"<<endl;

      }else{
         cout<<"W.A."<<endl;
         cout<<n<<" "<<len<<endl;
         for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
         }
         cout<<endl;
         break;
      }
    }
    return 0;
}