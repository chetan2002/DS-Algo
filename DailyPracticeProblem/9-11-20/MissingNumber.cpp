#include<bits/stdc++.h>
using namespace std;


//this is the best way to approach this question 
//time: O(N)
//space: constant = O(1)
//in this approach we first make all the non negative number as 1 and simultaneously check
//for the presence of 1 in the array if 1 is not initially present return 1 as answer
//then after all non negative and number greater than size of array are converted to zero
//then for every number , visit index number equal to that number and make the number negative if
//if the number is non negative on that index
//by this way we will visit all the indexes equal to numbers present in the array
//and then loop the array to find out what number is positive and hence
//the index number is not present in the original array as an element
int findMissingBestApproach(vector<int> v){
    int n = v.size();
    bool containsOne = false;
    for(int i=0;i<n;i++){
        if(v[i]==1){
            containsOne = true;
        }
        if(v[i]<=0 || v[i]>n){
            v[i]=1;
        }
    }
    if(!containsOne){
        return 1;
    }

    for(int i=0;i<n;i++){ 
            int val = v[i];
            int pos = abs(val)-1;
            if(pos>=n){
                continue;
            }
            if(v[pos]>0){
                v[pos]=v[pos]*(-1);
            }
    }

    for(int i=0;i<n;i++){
        if(v[i]>0){
            return i+1;
        }
    }
    return n;
}


//using sorting to arrange elements in ascending order 
//then check for every element if it's value is equal to the required numbe
//if it is equal then move forward
//if it is one less then than means the repeating previous number , move forward without increasing current value
//else return the current required
//Time: O(NlogN)
//space : O(1)
int findMissingUsingSorting(vector<int> v){
    sort(v.begin() , v.end());
    int i=1;
    for(auto c: v){
        if(c<1){

        }else{
            if(c!=i){
                if(c==i-1){

                }else{
                    return i;
                }
            }else{
                i++;
            }
        }
    }
    return i;  
}



//This approach uses a set for storing the values greater than 0
//then compare the values if they are present in the set
// Time: O(nlogn) = loop + insertion in set costs logn
//space : O(n)
int FindMissingUsingSet(vector<int> v){
    set<int> s;
    for(auto c: v){
        if(c>0){
            s.insert(c);
        }
    }
    int i=1;
    for(auto c: s){
        if(c!=i){
            return i;
        }
        i++;
    }
    return i;
}

int main(){
    //input 
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        v.push_back(val);
    }


    cout<<FindMissingUsingSet(v)<<endl;
    cout<<findMissingUsingSorting(v)<<endl;
    cout<<findMissingBestApproach(v)<<endl;
    return 0;
}
