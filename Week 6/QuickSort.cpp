//T.C--> O(NLOGN)
#include <iostream>
using namespace std;
 
int partition(int arr[], int start, int end){
 	int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 

    int pivotidx = start + count;
    swap(arr[pivotidx], arr[start]);
 
    int i = start, j = end;
 
    while (i < pivotidx && j > pivotidx) {
 
        while (arr[i] <= pivot)i++;
 
        while (arr[j] > pivot)j--;
 
        if (i < pivotidx && j > pivotidx)
            swap(arr[i++], arr[j--]);
    }
 
    return pivotidx;
}
 
void quickSort(int arr[], int start, int end)
{
 	if (start >= end)return;
 
    int p = partition(arr, start, end);
 
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}
 
int main()
{
	cout<<"Enter n: "<<endl;
 	int n;
 	cin>>n;
 	int arr[n];
 	cout<<"Enter array elements: "<<endl;
 	for(int i=0;i<n;i++)
 		cin>>arr[i];
    quickSort(arr, 0, n - 1);
 	cout<<"Sorted order is: "<<endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 142;
}
