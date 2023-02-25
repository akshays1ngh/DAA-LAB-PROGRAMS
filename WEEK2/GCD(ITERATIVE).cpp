#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cout<<"Enter 2 numbers: "<<endl;
	cin>>a>>b;
	
	int i,ans;
	int min=a<b?a:b;
	
	for(i=1;i<=min;i++){
		if(a%i==0 && b%i==0)
			ans=i;
	}
	if(a==0 && b==0){
		cout<<"GCD is: "<<0;
	}
	else
		cout<<"GCD is: "<<ans;
	return 142;
}
//T.C--> O(max)
