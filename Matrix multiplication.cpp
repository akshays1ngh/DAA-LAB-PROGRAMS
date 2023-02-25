#include<iostream>
using namespace std;

int main(){
	
	int r1,c1,r2,c2,i,j,k;
	//READ THE DIMENSIONS
	cout<<"Enter the order of matrix 1"<<endl;
	cin>>r1>>c1;

	cout<<"Enter the order of matrix 2"<<endl;
	cin>>r2>>c2;
	
	int mat1[r1][c1],mat2[r2][c2];
		
	if(r1!=c2){
		cout<<"Not possible: "<<endl;
		exit(0);
	}
	
	cout<<"Enter matrix 1 elements: "<<endl;
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			cin>>mat1[i][j];
		}
	}
	
	cout<<"Enter matrix 2 elements: "<<endl;
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++){
			cin>>mat2[i][j];
		}
	}
	cout<<"Resultant matrix is: "<<endl;
	
	//MULTIPLICATION PART
	int mult[r1][c2]={0};
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			mult[i][j]=0;
			for(k=0;k<r1;k++){
				mult[i][j]+=mat1[i][k]*mat2[k][j];
			}
		}
	}
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			cout<<mult[i][j]<<" ";
		}
		cout<<endl;
	}
	return 142;
}
