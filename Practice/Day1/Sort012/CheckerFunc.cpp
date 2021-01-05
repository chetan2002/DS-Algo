#include<bits/stdc++.h>
using namespace std;

void sort012count(int a[] , int n){
    int count0 = 0 , count1 = 0 , count2 = 0 ;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            count0++;
        }else 
        if(a[i]==1){
            count1++;
        }else{
            count2++;
        }
    }
    for(int i=0;i<n;i++){
        if(count0!=0){
            a[i]=0;
            count0--;
        }else
        if(count1!=0){
            a[i]=1;
            count1--;
        }else{
            a[i]=2;
            count2--;
        }
    }
}
void sort012(int a[], int n)
{
    // coode here 
    long long int ptr0 =0 , ptr2 = n-1;
    for(long long int i=ptr0;i<=ptr2;){
        if(a[i]==0){
            swap(a[i],a[ptr0]);
            ptr0++;
            i++;
        }else
        if(a[i]==2){
            swap(a[i],a[ptr2]);
            ptr2--;
        }else{
            i++;
        }
    }
    
}

int main(){
    srand(time(0));
    while(true){
        int n = rand()%5;
        int arr[n];
        for(int i=0;i<n;i++){
            arr[i] = rand()%3;
        }
        int arr1[n] , arr2[n];
        for(int i=0;i<n;i++){
            arr1[i]=arr[i];
            arr2[i]=arr[i];
        }
        sort012(arr1,n);
        sort012count(arr2 , n);
        bool printed = true;
        for(int i=0;i<n;i++){
            if(arr1[i]==arr2[i]){
                
            }else{
                printed=false;
                break;
            }
        }
        if(printed){
            cout<<"Checked"<<" ...OK"<<endl;
        }else{
            cout<<"Error!!!"<<endl;
            cout<<"N = "<<n<<endl;
            cout<<"array : ";
            for(int i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            cout<<"My Answer : ";
            for(int i=0;i<n;i++){
                cout<<arr1[i]<<" ";
            }
            cout<<endl;
            cout<<"Correct Answer : ";
            for(int i=0;i<n;i++){
                cout<<arr2[i]<<" ";
            }
            cout<<endl;
            cout<<"........................."<<endl;
            break;
        }
    }
    return 0;
}