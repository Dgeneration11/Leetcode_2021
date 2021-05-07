


class Solution {
public: 
    int minDistance(string word1, string word2){
        int M = word1.length(), N = word2.length();
        vector<vector<int>>dp(M+1, vector<int>(N+1, 0));
        
        for(int i=0; i<M+1; i++){
            for(int j=0; j<N+1; j++){
                if(i==0){
                    dp[i][j] = j;
                }
                else if(j==0){
                    dp[i][j] = i;
                }
                else if(word1[i-1]==word2[j-1]){
                    dp[i][j] = 0 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[M][N];
    }
};