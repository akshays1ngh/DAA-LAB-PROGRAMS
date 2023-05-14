#include <iostream>
using namespace std;
void subset(int idx,int arr[],int t,int ans[],int &k,int n,int s){
    
    if(idx==n){
        if(s==t){
            for(int i=0;i<k;i++)
                cout<<ans[i]<<" ";
            cout<<endl;
        }
        return;
    }
    s+=arr[idx];
    ans[k++]=arr[idx];
    subset(idx+1,arr,t,ans,k,n,s);
    //backtracking
    k--;
    s-=arr[idx];
    subset(idx+1,arr,t,ans,k,n,s);
}
int main(){
    int n;
    cout<<"Enter number of elements: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter elements: "<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int t;
    cout<<"enter target: "<<endl;
    cin>>t;
    int ans[100],k=0;
    cout<<"possible answers are: "<<endl;
    subset(0,arr,t,ans,k,n,0);
    return 0;   
}