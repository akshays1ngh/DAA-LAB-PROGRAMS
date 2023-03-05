
//T.C--> O(N* 2^N)
#include <iostream>
using namespace std;

//GENERATE ALL POSSIBLE SUBSETS AND EVALUATE FOR THE HIGHEST VALUE
void subset(int idx,int n,int wt[],int values[],int arr[],int target,int &ans,int k,int final[],int &final_k){
    if(idx==n){
        int wt1=0,v1=0;
        for(int i=0;i<k;i++){
            wt1+=wt[arr[i]];
            v1+=values[arr[i]];}
    if(wt1<=target){
        if(v1>ans){
            ans=v1;
            final_k=k;
            for(int i=0;i<k;i++)
                final[i]=wt[arr[i]];
        }
    }
        k=0;
        return;
    }
    arr[k++]=idx;
    subset(idx+1,n,wt,values,arr,target,ans,k,final,final_k);
    k--;
    subset(idx+1,n,wt,values,arr,target,ans,k,final,final_k);
}

int main()
{
    int n,target,ans;
    cout<<"Enter the number of weights: "<<endl;
    cin>>n;
    int wt[n],values[n];
    cout<<"Enter the wts: "<<endl;
    for(int i=0;i<n;i++)
        cin>>wt[i];
    cout<<"Enter the corr values: "<<endl;
    for(int i=0;i<n;i++)
        cin>>values[i];
    cout<<"Enter limiting weight: "<<endl;
    cin>>target;
    int arr[100],final[100],final_k=0;
    subset(0,n,wt,values,arr,target,ans,0,final,final_k);
    
    cout<<"Best possible value along with its corr wt: "<<endl;
    cout<<ans<<endl;
    for(int i=0;i<final_k;i++)
        cout<<final[i]<<" ";
    
    return 142;
}