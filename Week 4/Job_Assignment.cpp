
//T.C--> O(N * 2^N)
#include <bits/stdc++.h>
using namespace std;
int mat[20][20];

void permuteandcheck(int idx,int n,int mat[][20],int arr[],int &ans){
    
    if(idx==n){
        int s=0;
        for(int i=0;i<n;i++){
            s+=mat[arr[i]][i];
        }
        ans=s<ans?s:ans;
        return;
    }
    for(int i=idx;i<n;i++){
        swap(arr[i],arr[idx]);
        permuteandcheck(idx+1,n,mat,arr,ans);
        swap(arr[i],arr[idx]);
    }
    
}
int main(){
    int n,ans=INT_MAX;
    cout<<"Enter n: "<<endl;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
        arr[i]=i;
    
    cout<<"Enter job assignment matrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    
    permuteandcheck(0,n,mat,arr,ans);
    cout<<ans;
    return 142;
}