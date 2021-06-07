class Solution
{
public:
    int longestConsecutive(vector<int> &a)
    {

        if (a.empty())
        {
            return 0;
        }

        map<int, int> hash;

        int x{1};

        for (auto &i : a)
        {
            if (!hash[i])
            {
                hash[i] = 1;

                int left{hash[i - 1]}, right{hash[i + 1]};
                hash[i - left] = hash[i + right] = 1 + left + right;

                x = max(x, 1 + left + right);
            }
        }

        return x;
    }
};