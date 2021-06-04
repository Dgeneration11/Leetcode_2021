class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> dead{begin(deadends), end(deadends)};
        
        if(dead.count("0000")){
            return -1;
        }
        
        if(target=="0000"){
            return 0;
        }
        
        queue<string> que{{"0000"}};
        
        int x=0;
        while(!que.empty()){
            ++x;
            for(int i=que.size(); i>0; --i){
                string immediate = que.front();
                que.pop();
                
                for(int j=0; j<4; ++j){
                    char s = immediate[j];
                    //increasing the ith digit by 1
                    immediate[j] = immediate[j] == '9' ? '0' : immediate[j] + 1;
                    
                    if(immediate == target){
                        return x;
                    }
                    if(!dead.count(immediate)){
                        que.push(immediate);
                        dead.insert(immediate);
                    }
                    immediate[j] = s;
                    
                    //Now we should decrease by 1
                    immediate[j] = immediate[j] == '0' ? '9' : immediate[j] - 1;
                    if(immediate == target){
                        return x;
                    }
                    if(!dead.count(immediate)){
                        que.push(immediate);
                        dead.insert(immediate);
                    }
                    immediate[j] = s;
                }
            }
            
        }
        
        return -1;
    }
};