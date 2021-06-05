class Solution
{
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {

        long long mod = 1e9 + 7;
        long long res = 0, sum = 0;
        vector<pair<long long, long long>> engg;
        for (int i = 0; i < n; i++)
        {
            engg.push_back({efficiency[i], speed[i]});
        }

        sort(engg.begin(), engg.end(), greater<pair<int, int>>());

        multiset<int> c;
        for (long long i = 0; i < n; i++)
        {
            long long minimum_efficiency = engg[i].first;
            sum = sum + engg[i].second;
            res = max(res, sum * minimum_efficiency);

            c.insert(engg[i].second);
            if (c.size() > k - 1)
            {
                sum -= (*c.begin());
                c.erase(c.begin());
            }
        }

        return (int)(res % mod);
    }
};