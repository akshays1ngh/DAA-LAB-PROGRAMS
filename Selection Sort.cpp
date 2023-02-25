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
	int min;
	for(i=0;i<n-1;i++){
	    min=i;
	    for(j=i+1;j<n;j++){
		if(arr[j]<arr[min])
			min=j;
		}
		//SWAPPING
		t=arr[i];
		arr[i]=arr[min];
		arr[min]=t;
	}
	
	cout<<"Ordered elements: "<<endl;
	
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 142;
}
