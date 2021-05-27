class Solution {
private:
    int encrypt(const string& word) {
        int rt=0;
        for (auto const& c : word) rt|=1<<(c-'a');
        return rt;
    }
public:
    int maxProduct(vector<string>& words) {
        vector<int> encoded;
        for (auto const& word : words)
            encoded.push_back(encrypt(word));
        size_t rt=0, n=words.size();
        for (int i=0; i<n; ++i)
            for (int j=i+1; j<n; ++j)
                if ((encoded[i]&encoded[j])==0)
                    rt=max(rt, words[i].size()*words[j].size());
        return rt;
    }
};