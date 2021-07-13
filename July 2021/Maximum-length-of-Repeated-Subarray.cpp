class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int max_len = 0;
        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 1; j < dp[0].size(); j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
                max_len = max(max_len, dp[i][j]);
            }
        }
        return max_len;
    }
};