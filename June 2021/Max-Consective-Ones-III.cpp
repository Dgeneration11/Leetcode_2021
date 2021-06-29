class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int l = 0, r = 0;
        int x = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[r] == 1)
            {
                r++;
            }
            else
            {
                if (k == 0)
                {
                    while (nums[l++] != 0)
                        ;
                }
                else
                {
                    k--;
                }
                r++;
            }
            x = max(x, r - l);
        }
        return x;
    }
};