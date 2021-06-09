class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> pq; // value ,index
        pq.push({nums[0], 0});
        for (int i = 1; i < nums.size(); i++)
        {
            while (pq.top().second < (i - k))
            {
                pq.pop();
            }
            pair<int, int> curr = pq.top();
            curr.first += nums[i];
            curr.second = i;
            pq.push(curr);
            if (i == nums.size() - 1)
            {
                return curr.first;
            }
        }
        return pq.top().first;
    }
};