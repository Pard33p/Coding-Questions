#include <bits/stdc++.h>
using namespace std;

//search for largest element in bitonic array
int pivotSearch(int arr[], int low, int high)
{
    if(low <= high)
    {
        int mid = (low+high)/2;
        if((mid == 0 || arr[mid-1] < arr[mid]) && (mid == high || arr[mid+1] < arr[mid]) )
            return mid;
        else if(arr[mid] < arr[mid+1])
            return pivotSearch(arr,mid+1,high);
        return pivotSearch(arr,low,mid-1);
    }
    return -1;
}

//binary search to search in array sorted in increasing order
int binarySearch(int arr[], int low, int high, int x)
{
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] < x)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

//binary search to search in array sorted in decreasing order
int binarySearchDec(int arr[], int low, int high, int x)
{
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] < x)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

//searches the element x in bitonic array.
int search(int arr[], int n, int x)
{
    //find pivot(index of largest element in bitonic array in O(logn))
    int pivot = pivotSearch(arr,0,n-1);
    if(arr[pivot] == x)
        return pivot;
    int ans = -1;
    
    //search in left half(which is sorted in increasing order)
    if((ans = binarySearch(arr,0,pivot-1,x)) != -1)
        return ans;
        
    //search in right half(which is sorted in decreasing order)
    else
        return binarySearchDec(arr,pivot+1,n-1,x);
    
}

int main() {
    int t,n,x;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        int arr[n];
        for(int i = 0; i < n; i++)  
            cin >> arr[i];
        int index = search(arr,n,x);
        if(index == -1)
            cout << "OOPS! NOT FOUND\n";
        else
            cout << index << "\n";
    }
	//code
	return 0;
}
