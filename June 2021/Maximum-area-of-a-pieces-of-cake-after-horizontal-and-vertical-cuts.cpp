class Solution {
public:
    int maxArea(int h, int w, vector<int>& hori, vector<int>& vert) {
          
        hori.push_back(0);
        hori.push_back(h);
        
        vert.push_back(0);
        vert.push_back(w);
        
        sort(hori.begin(), hori.end()); //nlogn
        sort(vert.begin(), vert.end());
        
        int hori_area = 0;        
        for(int i=1; i<hori.size(); i++){
            hori_area = max(hori_area, abs(hori[i] - hori[i-1]));
        }
                            
        int vert_area = 0;
        for(int i=1; i<vert.size(); i++){
            vert_area = max(vert_area, abs(vert[i] - vert[i-1]));
        }
                            
        return (long long)hori_area * (long long)vert_area  % (long long)(pow(10, 9)+7);
                            
    }
};