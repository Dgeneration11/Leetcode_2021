class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> total = {nums[0]};

        for(int i=1; i<nums.size(); i++){
            total.push_back(total.back() + nums[i]);
        }
        return total;
    }
};