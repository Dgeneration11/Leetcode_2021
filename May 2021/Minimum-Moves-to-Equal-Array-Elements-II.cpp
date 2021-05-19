class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();
        
        //Sorting
        sort(nums.begin(), nums.end());
        int median=0;
        //calc mid
        if(n%2==0){
            median = (nums[n/2]+nums[n/2-1])/2;
        }
        else{
            median = nums[n/2];
        }
        
        int count=0;
        //final calc of count
        for(int i=0; i<nums.size(); i++){
            count = count + abs(median - nums[i]);
        }
            
        return count;       
    }
};