//https://ide.codingblocks.com/s/383711
#include<bits/stdc++.h>
using namespace std;

//using bitmasking
//consider 3 digits in array 
//2 , 5, 6
// then start from 0 to 7(2^n -1) since it will be like
// 0 , 0 , 0 
// 0, 0 , 1
// 0 , 1 , 0
// .  .   .
// 1 , 1 ,1

// and we can pprint corresponding index to the set bits each time
void printSubset(vector<int> v , int n){
    int x = pow(2,n)-1;

    for(int i=0;i<=x;i++){
        int num = i;
        int bitpos = 0;
        while(num != 0){
            if((num&1)==1){
                cout<< v[bitpos] << " " ;
            }
            num = num>>1;
            bitpos++;
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        v.push_back(val);
    }
    printSubset(v,n);
    return 0;
}