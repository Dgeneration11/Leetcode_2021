class Solution {
public:
    bool isInterleave(string x, string y, string z){
    int xlen = x.length(), ylen = y.length(), zlen = z.length();
    if (zlen != xlen+ylen) return false;
    vector<vector<bool>> f(xlen+1, vector<bool>(ylen+1, false));
    
    //basecase: empty string is interleaving of two empty strings
    f[0][0] = true;
    //basecase: m == 0 --> compare(z[:n], y[:n])
    for(int i = 1; i <= ylen; i++){
        if (y[i-1] == z[i-1])
            f[0][i] = f[0][i-1];
    }
    //basecase: n == 0 --> compare(z[:m], x[:m])
    for(int i = 1; i <= xlen; i++){
        if (x[i-1] == z[i-1])
            f[i][0] = f[i-1][0];
    }
    for(int i = 1; i <= xlen; i++) {
        for(int j = 1; j <= ylen; j++) {
            int k = i + j;
            char xlast = x[i-1], ylast = y[j-1], zlast = z[k-1];
            if (zlast == xlast && zlast == ylast){
                f[i][j] = (f[i-1][j] || f[i][j-1]);
            }
            else if (zlast == xlast) {
                f[i][j] = f[i-1][j];
            }
            else if (zlast == ylast) {
                f[i][j] = f[i][j-1];
            }
        }
    }
    return f[xlen][ylen];
}
};

