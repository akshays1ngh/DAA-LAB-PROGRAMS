#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	
	if(a==0)return b;
	if(b==0)return a;
	
	return gcd(b,a%b);
	
}
int main(){
	int a,b;
	cout<<"Enter 2 numbers: "<<endl;
	cin>>a>>b;
	
	cout<<"GCD is: "<<gcd(a,b);
	return 0;
	
}
