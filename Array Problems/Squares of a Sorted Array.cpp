class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> sq;
        
        for(int i=0; i<n; i++){
            sq.push_back(nums[i]*nums[i]);
        }
        sort(sq.begin(), sq.end()); //O(nlogn)
        return sq;
    }
};