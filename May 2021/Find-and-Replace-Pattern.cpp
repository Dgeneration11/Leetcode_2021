class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(int i=0; i<words.size(); i++){
            if(words[i].length() != pattern.length())continue;
            bool flag = true;
            for(int j = 1; j<pattern.length(); j++){
                if(count(pattern.begin(), pattern.end(), pattern[j]) != 
                   count(words[i].begin(), words[i].end(), words[i][j])){
                    flag = false;
                    break;
                }
                if((pattern[j-1] == pattern[j] && words[i][j-1] != words[i][j]) ||
                   (pattern[j-1] != pattern[j] && words[i][j-1] == words[i][j])){
                    flag=false;
                    break;
                }
            }
            if(flag)ans.push_back(words[i]);
        }
        return ans;
    }
};