#include<bits/stdc++.h>
using namespace std; 
// Helper Function to calculate the number of inversions on merging 
int merge(vector<int> &arr, int start, int end){
    int count = 0 ;
    int i = start ; 
    int mid = (start + end)/2 ; 
    int j = mid + 1 ; 

    vector<int> temp ; 
    // compare elements and count inversions
    while(i <= mid and j <= end){
        if(arr[i] > arr[j]){
            // all elements in left array will count towards inversions
            count += mid - i + 1 ;  
            temp.push_back(arr[j++]) ; 
        }else{
            temp.push_back(arr[i++]) ; 
        }
    }
    // copy remaining elements from first array to new array
    while(i <= mid){
        temp.push_back(arr[i++]) ; 
    }
    // copy remaining elements from second array to new array
    while(j <= end){
        temp.push_back(arr[j++]) ; 
    }
    // copy back elements from new array to original array
    int k = 0 ; 
    for(int i = start ; i <= end ; i++){
        arr[i] = temp[k++] ; 
    }

    return count ; 
}
// Worker Function
int countInversions(vector<int> &arr, int start, int end){
    // Base Case 
    if(start >= end){
        return 0 ; 
    }
    int mid = (start + end)/2 ; 
    // Count Inversions on left part of array
    int countLeft = countInversions(arr,start,mid)  ;
    // Count Inversions on right part of array
    int countRight = countInversions(arr,mid+1,end) ; 
    // Count Inversions when merging 
    int mergeCount = merge(arr,start,end) ; 
    // Return total count 
    int total = countLeft + countRight + mergeCount ; 
    return total ; 
}

int main(){
    vector<int> arr ;  
    int n ; 
    cout<<"Enter the number of elements:" ; 
    cin>>n ; 
    cout<<"Enter the array of elements:"  ; 
    for(int i = 0 ; i < n ; i++){
        int num ; 
        cin>>num ; 
        arr.push_back(num) ; 
    }
    cout<<"Number of inversions: "<<countInversions(arr,0,n-1) ;  
}