def merge(arr,start,mid,end):
    temp = []
    i = start 
    j = mid + 1
    # compare elements and copy to new array
    while(i<=mid and j<=end):
        if(arr[i] <= arr[j]):
            temp.append(arr[i])
            i += 1
        else:
            temp.append(arr[j]) 
            j += 1
    # copy remaining elements from first array to new array
    while(i<=mid):
        temp.append(arr[i])
        i += 1
    # copy remaining elements from second array to new array
    while(j<=end):
        temp.append(arr[j])
        j += 1
    # copy element back from new array to original array
    k = 0 
    for i in range(start, end+1):
        arr[i] = temp[k]
        k += 1

def merge_sort(arr,start,end):
    if(start >= end):
        return 
    mid = (start + end)//2 
    merge_sort(arr,start,mid) 
    merge_sort(arr,mid+1,end) 
    merge(arr,start,mid,end)

def main():
    print("Enter number of elements:")
    n = int(input()) 
    print("Enter array of elements:")
    arr = [int(i) for i in input().split()]
    merge_sort(arr,0,n-1)
    print("Sorted:")
    print(arr)

main()