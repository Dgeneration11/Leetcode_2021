class Solution {
public:
    int maximumGap(vector<int>& a) {
        sort(a.begin(), a.end());
        
        int n = a.size()-1;
        int max_diff=0;
        for(int i=0;i<n;i++)
            max_diff = max(max_diff, a[i+1]-a[i]);

        return max_diff;
    }
};