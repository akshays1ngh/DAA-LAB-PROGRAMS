#include <bits/stdc++.h>
using namespace std;
 
 int isprime(int n){
 	
 	int i,f=0;
 	for(i=2;i<=sqrt(n);i++){
 		if(n%i==0){
 			f=1;
 			break;
		 }
	 }
	 
	 if(f==0)return 1;
	 return 0;
	 
 }
 
int main(){
	
	int a,b,gcd=1;
	cout<<"Enter 2 numbers: "<<endl;
	cin>>a>>b;

	int max=a>b?a:b;
	int min=a<b?a:b;
	
	for(int i=2;i<=max;i++){
		while(isprime(i) && max%i==0 && min%i==0){
			gcd=gcd*i;	
			max/=i;		
			min/=i;
	}
}
	if(a==0 && b==0){
		cout<<"GCD is: "<<0;
	}
	else
		cout<<"GCD is: "<<gcd;
	return 142;
	
}
