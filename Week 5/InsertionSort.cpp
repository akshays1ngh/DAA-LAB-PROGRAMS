/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;
void insertionsort(int n,int arr[]){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    
}
int main()
{
    int n;
    cout<<"Enter number of elements: "<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter elements: "<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    insertionsort(n,a);
    cout<<"Sorted elements are: "<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}