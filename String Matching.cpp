#include<bits/stdc++.h>
using namespace std;

int main(){
	
	string s,patt;
	//ACCEPTING ORIGINAL STRING AND THE PATTERN WHICH IS TO BE FOUND
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
		//IF THE PATTERN IS FOUND, PRINT THE STARING INDEX AND EXIT..
		if(j==m){
		    cout<<"Pattern found at index: "<<i<<endl;
		    break;
		}
	}
	return 142;
}	
	
