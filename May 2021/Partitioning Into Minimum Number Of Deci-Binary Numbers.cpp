class Solution {
public:
    int minPartitions(string n) {
        
        int length = n.length();
        int x=0;
        for(int i=0; i<length; i++){
            int dig = n[i] - '0';
            
            x = max(x, dig);
        }
        
        return x;
        
    }
};