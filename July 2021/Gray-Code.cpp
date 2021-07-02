class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> res;
        res.push_back(0);
        if (n == 0)
        {
            return res;
        }
        res.push_back(1);

        int p = 1;
        for (int i = 2; i <= n; i++)
        {
            p *= 2;
            for (int j = res.size() - 1; j >= 0; j--)
            {
                res.push_back(p + res.at(j));
            }
        }

        return res;
    }
};
