#include <bits/stdc++.h>
using namespace std;

//function to check if num(represented as bit string) is disible by 3
bool isMultiple3(string num)
{
    //variables to store count of 1's at even and odd positions
    int evenCount = 0, oddCount = 0;
    for(int i = num.length()-1; i >= 0; i -= 2)
    {
        if(num[i] == '1')
            oddCount++;
        if(i > 0 and num[i-1] == '1')
            evenCount++;
    }
    
    //if this difference is divisible by 3 then given num is divisible by 3
    return abs(oddCount - evenCount) % 3 == 0;
}

int main() {
    int t; //no. of test cases
    cin >> t;
    while(t--)
    {
        string num; //bit string
        cin >> num;
        cout << isMultiple3(num) << "\n";
    }
	//code
	return 0;
}
