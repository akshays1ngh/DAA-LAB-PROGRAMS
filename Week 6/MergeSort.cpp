#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high,int n) {
    int temp[n],k=0; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[k++]=arr[left];
            left++;
        }
        else {
            temp[k++]=arr[right];
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp[k++]=arr[left];
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp[k++]=arr[right];
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high,int n) {
    if (low >= high) 
        return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid,n);  // left half
    mergeSort(arr, mid + 1, high,n); // right half
    merge(arr, low, mid, high,n);  // merging sorted halves
}

int main() {
    cout<<"Enter the value of n: "<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: "<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    mergeSort(arr, 0, n - 1,n);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}