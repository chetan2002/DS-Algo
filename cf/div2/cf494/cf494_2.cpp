#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ll a , b , c;
    cin>>a>>b>>c;
    string al = "";
    ll done0 = 0,done1 = 0;
    for(int i=0;i<c;i++){
        if(a>=b){
            if(i%2==0){
                al+='0';
                done0++;
            }else{
                al+='1';
                done1++;
            }
        }else{
            if(i%2==1){
                al+='0';
                done0++;
            }else{
                al+='1';
                done1++;
            }
        }
        
    }
    ll remA = a-done0;
    ll remB = b-done1;
    string fina = "";
    string s1(remA , '0');
    string s2(remB , '1');
    if(a>=b){
        fina = s1+al+s2;
    }else{
        fina = s2+al+s1;
    }
    cout<<fina<<endl;
    return 0;
}