#include <iostream>
#include <vector>

using namespace std;

void comparison_count_sort(vector<int>& arr) {
    int n = arr.size();
    // find the maximum value in the array
    int max_val = arr[0];
    for(int i = 1; i < n; i++) 
        if(arr[i] > max_val) 
            max_val = arr[i];
    // create an array to store the count of each value
    vector<int> count(max_val + 1, 0);
    // count the number of occurrences of each value
    for(int i = 0; i < n; i++) 
        count[arr[i]]++;
    // compute the prefix sum of the count array
    for(int i = 1; i <= max_val; i++) 
        count[i] += count[i-1];
    // create a temporary array to store the sorted array
    vector<int> temp(n);
    // sort the array
    for(int i = n-1; i >= 0; i--) {
        temp[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    // copy the sorted array back to the original array
    for(int i = 0; i < n; i++) 
        arr[i] = temp[i];
}

int main() {
    vector<int> arr ;
    int i,n,x;
    cout<<"Counting sort\n";
    cout<<"Enter number of elements:";
    cin>>n;
    for(i=0;i<n;i++)
    {
    	cin>>x;
    	arr.push_back(x);   	
	}
    comparison_count_sort(arr);
    cout << "Sorted array: ";
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}
