#include <bits/stdc++.h>
using namespace std;

int maxArea(int hist[], int n)
{
    stack<int> s;
    int ans = 0;
    int i;
    for(i = 0; i < n;)
    {
        if(s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
        else
        {
            int tp = s.top();
            s.pop();
            
            int area = hist[tp] * (s.empty() ? i : i - s.top() - 1);
            ans = max(ans,area);
        }
    }
    
    while(!s.empty())
    {
        int tp = s.top();
        s.pop();
        int area = hist[tp] * (s.empty() ? i : i - s.top() - 1);
        ans = max(ans,area);
    }
    return ans;
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
        cout << maxArea(arr,n) << "\n";
    }
	//code
	return 0;
}
