#include<bits/stdc++.h>
using namespace std; 

void merge(vector<int> &arr, int start, int mid, int end){
    vector<int> temp ; 
    int i = start ; 
    int j = mid + 1 ; 
    // compare elements and copy to new array 
    while(i<=mid and j<=end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]) ; 
        }else{
            temp.push_back(arr[j++]) ; 
        }
    }
    // copy remaining elements from first array to new array 
    while(i<= mid){
        temp.push_back(arr[i++]) ;
    }
    // copy remaining elements from second array to new array
    while(j<= end){
        temp.push_back(arr[j++]) ;
    }
    // copy back elements from new array to original array
    int k = 0 ; 
    for(int i = start ; i<= end ; i++){
        arr[i] = temp[k++] ; 
    }
}
void mergeSort(vector<int> &arr,int start,int end){
    if(start>=end){
        return ; 
    }
    int mid = (start+end)/2 ;  
    mergeSort(arr,start,mid) ;
    mergeSort(arr,mid+1,end) ; 
    merge(arr,start,mid,end) ;  
}
int main(){
    vector<int> arr ; 
    int n  ;
    cout<<"Enter number of elements:" ; 
    cin>>n ; 
    cout<<"Enter array of elements:" ; 
    for(int i = 0 ; i < n ; i++){
        int num ; 
        cin>>num ; 
        arr.push_back(num) ; 
    }
    mergeSort(arr,0,n-1) ; 
    cout<<"Sorted:"<<endl ; 
    for(auto it = arr.begin(); it != arr.end(); it++){
        cout<<*it<<" "; 
    }
}