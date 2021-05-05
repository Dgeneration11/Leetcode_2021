class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        int jumps = 0;
        int cur_end = 0, cur_max_reach = 0;
        
        /*
        i stops at n-2, 
        that's because we don't need to jump 
        if we have reached n-1
        */
        for(int i = 0; i < n-1; ++i){
            cur_max_reach = max(cur_max_reach, i + nums[i]);
            
            if(i == cur_end){
                cur_end = cur_max_reach;
                ++jumps;
            }
        }
        
        return jumps;
    }
};