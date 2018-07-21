#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

// multiplies array ans[](representing a number in reverse order) by x
int multiply(int ans[], int size, int x)
{
    int carry = 0;
    int prod;
    for(int i = 0; i < size; i++)
    {
        prod = ans[i] * x + carry;  
        ans[i] = prod%10;  //store last digit to array
        carry = prod/10;    // and remaining digits to carry
    }
    while(carry)
    {
        ans[size] = carry%10;
        carry /= 10;
        size++;
    }
    return size;
    
}

void factorial(int n)
{
    int ans[MAX];
    
    ans[0] = 1;
    int size = 1;
    // n! = 1 * 2 * 3 * .... * n
    for(int x = 2; x <= n; x++)
        size = multiply(ans,size,x);
   
   for(int i = size-1; i >= 0; i--)
        cout << ans[i];
    cout << "\n";
}

int main() {
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        factorial(n);
    }
	//code
	return 0;
}
