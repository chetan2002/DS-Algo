#include<bits/stdc++.h>
using namespace std;


//This method uses prefix and suffix array for each position and returns the product of suffix and prefix of the element
//Time : O(n) and Space : O(3n);
vector<long long int> findMyNewArrayUsingPrefixArrays(vector<long long int> v){
    int n=v.size();
    vector<long long int> prefix(n,1);
    vector<long long int> suffix(n,1);
    prefix[0] = v[0];
    suffix[n-1] = v[n-1];
    //to find prefix array
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]*v[i];
    }
    //to find suffix array
    for(int i=n-2;i>=0;i--){
        suffix[i] = suffix[i+1]*v[i];
    }
    vector<long long int> newArray(n,1);
    for(int i=0;i<n;i++){
        if(i==0){
            newArray[i] = suffix[i+1];
        }else
        if(i==n-1){
            newArray[i] = prefix[i-1];
        }else{
            newArray[i] = prefix[i-1]*suffix[i+1];
        }
    }
    return newArray;
}


//using division method , 
//store the product for all elements and 
//then for each position divide the product by the element in original array 
//to get the element in new array
//consider the zero elements in array 
//Time:O(n) and space : O(n)
vector<long long int> findMyNewArrayDivisionMethod(vector<long long int> v){
    int n=v.size();
    long long int mul = 1;
    bool isZero = false;
    int countzero = 0;
    for(auto c: v){
        if(c==0){
            isZero=true;
            countzero++;
        }else{
            mul*=c;
        }
    }
    vector<long long int> a(n,mul);
    if(isZero){
        if(countzero>1){
            for(int i=0;i<n;i++){
                a[i] = 0;
            }
            return a;
        }
        if(countzero==1){
            for(int i=0;i<n;i++){
                if(v[i]!=0){
                    a[i] = 0;
                }else{
                    a[i] = mul;
                }
            }
        }
    }else{
        for(int i=0;i<n;i++){
            a[i] = a[i]/v[i];
        }
    }
    
    return a;
}

void print(vector<long long int> a){
     for(auto c: a){
        cout<<c<<" ";
    }
    cout<<endl;

}
int main(){
    int n;
    cin>>n;
    vector<long long int> v;
    for(int i=0;i<n;i++){
        long long int val ;
        cin>>val;
        v.push_back(val);
    }

    //using division
    vector<long long int> a =findMyNewArrayDivisionMethod(v);
    print(a);

    //not using division(suffix and prefix array)
    vector<long long int> b = findMyNewArrayUsingPrefixArrays(v);
    print(b);

    return 0;
}
