#include <bits/stdc++.h>
using namespace std;

void stock(int arr[], int n)
{
    //to store (buy_index, sell_index) pairs
    pair<int, int> ans[n/2+1];
    //no. of buy-sell pairs
    int count = 0;
    int i = 0;
    while(i < n-1)
    {
        //find local minima
        while(i < n-2 and arr[i+1] <= arr[i])
            i++;
        if(i == n-1)
            break;
        ans[count].first = i;
        i++;
        
        //find local maxima
        while(i < n and arr[i] >= arr[i-1] )
            i++;
        ans[count].second = i-1;
        if(ans[count].first != ans[count].second)
            count++;
    }
    if(count == 0)
        cout << "No Profit";
    else
    {
        for(int i = 0; i < count; i++)
            cout << "(" << ans[i].first << " " << ans[i].second << ") ";
        
    }
}

int main() {
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        stock(arr,n);
        cout << "\n";
    }
	//code
	return 0;
}
