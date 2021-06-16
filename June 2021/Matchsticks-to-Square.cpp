class Solution {
public:
    bool solve(vector<int>& matchsticks, int i, vector<int> sides){
        if(i == matchsticks.size()){
            if(sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0)
                return true;
            return false;
        }
        for(int j=0; j<4; j++){
            if(matchsticks[i] > sides[j]){
                continue;
            }
            sides[j] -= matchsticks[i];
            
            if(solve(matchsticks, i+1, sides)) return true;
            sides[j] += matchsticks[i];
        }  
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if(n<4) return false;
        int  p = 0;
        for(auto x: matchsticks){
            p += x;
        }
        if(p%4!=0){
            return false;
        }
        sort(matchsticks.rbegin(), matchsticks.rend());
        int side = p/4;
        vector<int> sides{side, side, side, side};
        
        return solve(matchsticks, 0, sides);
    }
};