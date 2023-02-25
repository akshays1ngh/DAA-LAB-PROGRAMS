//T.C--> O(N*M) (WHERE N IS THE LENGTH OF THE TEXT AND M IS THE LENGTH OF THE PATTERN) 
#include<bits/stdc++.h>
using namespace std;

int main(){
	
	string s,patt;
	cout<<"Enter string: "<<endl;
	getline(cin,s);
	cout<<"Enter pattern to be found: "<<endl;
	getline(cin,patt);
	
	int n=s.length(),m=patt.length(),i,j;
	
	for(i=0;i<=n-m;i++){
	    
		for(j=0;j<m;j++){
			if(s[i+j]!=patt[j])
				break;
		}
		if(j==m){
			cout<<"Pattern found at index: "<<i<<endl;
		    break;
		}
	}
	return 142;
}	
	
