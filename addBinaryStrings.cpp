#include <bits/stdc++.h>
using namespace std;

string addBinaryStrings(string a, string b)
{
    //string to store sum of two strings
    string res = "";
    int s = 0;        
    int i = a.length()-1;
    int j = b.length()-1;
    
    //s==1 if both strings are done but there is carry
    while(i >= 0 or j >= 0 || s == 1) 
    {
        //add bits
        s += (i >= 0) ? (a[i]-'0') : 0; 
        s += (j >= 0) ? (b[j]-'0') : 0;
        //update result
        res = char(s%2 + '0') + res;
        //update carry
        s /= 2;
        i--,j--;
    }
    return res;
    
}

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        string a,b;
        cin >> a >> b;
        cout << addBinaryStrings(a,b) << "\n";
    }
	//code
	return 0;
}
