class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        vector<int> a;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                count++;
            }
            else{
                a.push_back(count);
                count=0;
            }
        }
        a.push_back(count);
        sort(a.begin(), a.end());
        return a.back();
    }
};