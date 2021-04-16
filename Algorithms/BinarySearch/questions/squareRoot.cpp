#include<iostream>
using namespace std;

double sqrt(int n , int p = 3){
    int s = 0 , e = n;
    double ans = -1;
    while(s<=e){
        int mid = (s+e)/2;
        if(mid*mid == n){
            return mid;
        }
        if(mid<n/mid){
            ans = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }

    }

    //floating part
    double val = 0.1;
    for(int i=1;i<=p;i++){
        while(ans*ans<=n){
            ans+=val;
        }
        ans-=val;
        val /=10;
    }
    return ans;
}

int main(){
    int n ;
    cin>>n;
    cout<<sqrt(n , 3)<<endl;
    return 0;
}