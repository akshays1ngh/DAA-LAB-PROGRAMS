#include<iostream>
using namespace std;

void sort(int arr[],int n){
	for(int i=0;i<n;i++){
		int key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
}
}
int main(){
	int n;
	cout<<"Enter number of elements: "<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter elements: "<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,n);
	cout<<"Enter target ele: "<<endl;
	int target;
	cin>>target;
	int mid,l=0,r=n-1,ans=-1;
	while(l<=r){
		mid=l+(r-l)/2;
		if(arr[mid]==target){
			ans=mid;
			break;
		}
		if(arr[mid]<target)
			l=mid+1;
		else
			r=mid-1;
	}
	if(ans!=-1)
		cout<<"Found at index: "<<ans;
	else
		cout<<"Not Found";
	return 142;
}
