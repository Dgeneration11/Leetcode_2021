class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {

        int count = 0, count1 = 0, result = 0;
        for (auto &x : nums)
        {
            if (x < left)
            {
                count++;
            }
            else if (left <= x && x <= right)
            {
                count1 = ++count;
            }
            else
            {
                count1 = 0;
                count = 0;
            }
            result = result + count1;
        }
        return result;
    }
};