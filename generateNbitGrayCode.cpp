void generateCode(int n)
{
    vector<string> ans;
    ans.push_back("0");
    ans.push_back("1");
    for(int i = 2; i < (1 << n); i = i << 1)
    {
        //add previous codes to ans in reverse order
        for(int j = i-1; j >= 0; j--)
            ans.push_back(ans[j]);
            
        //append "0" to first half
        for(int j = 0; j < i; j++)
            ans[j] = "0" + ans[j];
            
        //append "1" to second half
        for(int j = i; j < 2*i; j++)
            ans[j] = "1" + ans[j];
    }
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}
