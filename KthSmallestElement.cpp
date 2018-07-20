#include <bits/stdc++.h>
using namespace std;

//standard quickSort partiton function
int partition(int arr[], int low, int high)
{
    int x = arr[high], i = low;
    for(int j = low; j < high; j++)
    {
        if(arr[j] <= x)
        {
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[high]);
    return i;
}

//randomized partition to improve average time complexity
int random_partition(int arr[], int low, int high)
{
    int n = high-low+1;
    int pivot = rand()%n;
    swap(arr[low+pivot],arr[high]);
    return partition(arr,low,high);
}
//function to find Kth largest element in array
int kthSmallest(int arr[], int low, int high, int k)
{
    //check if k is less than or equal to current array size
    if(k > 0 and k <= (high-low+1))            
    {
        int pos = random_partition(arr,low,high);
        //if this pos is kth smallest element, return it.
        if(pos - low == k-1)
            return arr[pos];
        //if this position is greater than k then call left subarray
        else if(pos - low > k-1)
            return kthSmallest(arr,low,pos-1,k);
        //else call right subarray. NOTE THE VALUE OF LAST ARGUMENT.
        return kthSmallest(arr,pos+1,high, k - ((pos+1)-low));
    }
    return INT_MAX;
}

int main() {
    int t,n,k;
    cin >> t; //number of test cases
    while(t--)
    {
        cin >> n; //array size
        int arr[n];
        for(int i = 0; i < n;i++)
            cin >> arr[i];
        cin >> k;
        cout << kthSmallest(arr,0,n-1,k) << "\n";
    }
	return 0;
}
