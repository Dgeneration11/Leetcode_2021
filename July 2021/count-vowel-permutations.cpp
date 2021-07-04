class Solution
{
public:
    int countVowelPermutation(int n)
    {
        int mod = 1000000007;
        vector<vector<long long int>> dp(n + 1, vector<long long int>(5));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (i == 1)
                    dp[i][j] = 1;
                else if (j == 0)
                {
                    dp[i][j] = ((dp[i - 1][1] + dp[i - 1][2]) % mod + dp[i - 1][4]) % mod;
                }
                else if (j == 1)
                {
                    dp[i][j] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
                }
                else if (j == 2)
                {
                    dp[i][j] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
                }
                else if (j == 3)
                {
                    dp[i][j] = (dp[i - 1][2]) % mod;
                }
                else if (j == 4)
                {
                    dp[i][j] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
                }
            }
        }
        int s = 0;
        for (int i = 0; i < 5; i++)
        {
            s = (s + dp[n][i]) % mod;
        }
        return s;
    }
};