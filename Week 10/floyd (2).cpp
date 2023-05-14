#include <iostream>
using namespace std;
int main(){
    
	    int i,j;
	    int n;
	    cout<<"Enter number of nodes: "<<endl;
	    cin>>n;
	    int matrix[n][n];
	    cout<<"Enter adj matrix exhibiting wts and -1 for no connections: "<<endl;
	    for(i=0;i<n;i++)
	        for(j=0;j<n;j++)
	            cin>>matrix[i][j];
	       
	   for(i=0;i<n;i++){
	       for(j=0;j<n;j++){
	           if(matrix[i][j]==-1)
	            matrix[i][j]=1e9;
	       }
	   }
	   //floyd algo
	   for(int via=0;via<n;via++){
	       for(i=0;i<n;i++){
	           for(j=0;j<n;j++){
	               matrix[i][j]=min(matrix[i][j],(matrix[i][via]+matrix[via][j]));
	           }
	       }
	   }
	   //rechange 1e9 to -1
	   for(i=0;i<n;i++){
	       for(j=0;j<n;j++){
	           if(matrix[i][j]==1e9)
	            matrix[i][j]=-1;
	       }
	   }
	   //print the final matrix with cost effective routes
	   cout<<"final matrix with cost effective routes"<<endl;
	   for(i=0;i<n;i++){
	        for(j=0;j<n;j++){
	            cout<<matrix[i][j]<<" ";
	        }
	        cout<<endl;
	   }
	   return 0;
}