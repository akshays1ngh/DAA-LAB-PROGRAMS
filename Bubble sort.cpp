#include<iostream>
using namespace std;

int main(){
	
	int n,t;
	cout<<"Enter the value of n: "<<endl;
	cin>>n;
	int arr[n];
	
	int i,j;
	cout<<"Enter elements: "<<endl;
	for(i=0;i<n;i++)
		cin>>arr[i];
	
	for(i=0;i<n-1;i++){
	    for(j=0;j<n-i-1;j++){
		if(arr[j]>arr[j+1]){
		//SWAPPING 
		    t=arr[j];
		    arr[j]=arr[j+1];
		    arr[j+1]=t;
		}
	}
}
	
	cout<<"Ordered elements: "<<endl;
	
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 142;
}
