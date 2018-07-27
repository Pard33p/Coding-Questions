int maxArea(int M[MAX][MAX],int n,int m)
{
    int dp[n][m];
    for(int i = 0; i < n; i++)
        dp[i][0] = M[i][0];
    for(int j = 0; j < m; j++)
        dp[0][j] = M[0][j];
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(M[i][j] == 1)
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
            else
                dp[i][j] = 0;
        }
    }
    int maxi = dp[0][0];
    int I=0, J=0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(maxi < dp[i][j])
            {
                I = i;
                J = j;
                maxi = dp[i][j];
            }
        }
    }       
    return abs((I-maxi)*(J-maxi));
    //Your code here
}
