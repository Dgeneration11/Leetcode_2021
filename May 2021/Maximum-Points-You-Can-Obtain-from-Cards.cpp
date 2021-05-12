class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l_sum[k+1];
        int r_sum[k+1];
        
        l_sum[0]=0;
        r_sum[0]=0;
        
        for(int i=1; i<=k; i++){
            l_sum[i] = l_sum[i-1] + cardPoints[i-1];                       
        }
        int size = cardPoints.size();
        for(int i=1; i<=k; i++){
            r_sum[i] = r_sum[i-1] + cardPoints[size-i];
        }
        
        int sum = 0;
        for(int i=0; i<=k; i++){
            sum = max(l_sum[i] + r_sum[k-i], sum);
        }
        
        return sum;
    }
};