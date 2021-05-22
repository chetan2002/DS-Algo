#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll maxsum(vector<ll> v, ll k)
{

    ll csum=0;
    for(int i=0;i<k;i++) csum+=v[i];
    ll i=k;
    ll maxs=csum;
    while(i<v.size())
    {
        csum+=v[i]-v[i-k];
        maxs=max(csum,maxs);
        i++;

    }
     return maxs;

}

double answer2(ll n , ll b , ll a , vector<ll> v ){
     double ans=0;
        for(int j=a;j<=b;j++)
        {   if(j==0){
                continue;
            }
            int x=maxsum(v,j);
            double cavg= x/(double)j;
            ans=max(ans,cavg);
        }

        return ans;
}
double answer(ll n , ll b , ll a , vector<ll> v){
    double maxAvg = 0;
    for(int i=0;i<n;i++){
        double sum = 0;
        for(int j=i;j<n;j++){
            int totalNumber = (j-i)+1;
            sum+=v[j];
            if(totalNumber<=b and totalNumber>=a){
                double ansAvg = (sum)/(1.0 * totalNumber);
                maxAvg = max(ansAvg , maxAvg);
            }
        }
    }
    return maxAvg;
}
int main(){
   
    // srand(time(0));
    while(true){    
        ll n , b , a;
        n = 5;
        b = 4;
        a = 3;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            v[i] = rand()%200;
        }
        

        ll ans1 = answer(n, b, a , v);
        ll ans2 = answer2(n , b , a , v);
        if(ans1 == ans2){
            cout<<"Ok"<<endl;
        }else{
            cout<<"TestCase Failed"<<endl;
            cout<<n<<" "<<b<<" "<<a<<endl;
            for(auto c: v){
                cout<<c<<" ";
            }
            cout<<endl;
            break;
        }
    }
    return 0;
}