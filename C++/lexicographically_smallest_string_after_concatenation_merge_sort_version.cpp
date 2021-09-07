// MERGE SORT VERSION - LEXIOGRAPHICALLY SMALLEST STRING AFTER CONCATENATION 

#include<bits/stdc++.h>
using namespace std; 
void mergeStrings(vector<string> &arr, int start, int end){
    vector<string> temp ;
    int mid = (start + end)/2 ;  
    int i = start ;  
    int j = mid + 1   ;
    // merge and compare strings 
    while(i <= mid and j <= end){
        string leftRight = arr[i] + arr[j];  
        string rightLeft = arr[j] + arr[i] ; 
        if(leftRight < rightLeft){
            temp.push_back(arr[i++]) ; 
        }else{
            temp.push_back(arr[j++]) ; 
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
}
void sortStringArray(vector<string> &arr, int start, int end){
    if(start >= end){
        return ; 
    }
    int mid = (start+end)/2 ; 
    sortStringArray(arr, start, mid);
    sortStringArray(arr,mid+1,start) ; 
    mergeStrings(arr,start,end) ; 
}
int main(){
    vector<string> arr ; 
    int n ; 
    cout<<"Enter number of strings:" ; 
    cin>>n ; 
    cout<<"Enter array of strings:" ; 
    for(int i = 0 ; i < n ; i++){
        string s ; 
        cin>>s ; 
        arr.push_back(s) ; 
    }
    // arrange in the correct order , basically modified merge sort 
    sortStringArray(arr,0,n-1) ; 
    // Concatenate to give output 
    string concatenated = "" ; 
    for(auto it = arr.begin() ; it != arr.end() ; it++){
        concatenated += *it ; 
    }
    cout<<"Smallest String after concatenation"<<endl ; 
    cout<<concatenated ; 
}