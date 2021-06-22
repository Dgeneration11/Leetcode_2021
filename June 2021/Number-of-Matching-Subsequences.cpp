class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        unordered_map<char, vector<pair<int, int>>> mp;

        for (int i = 0; i < words.size(); i++)
        {
            mp[words[i][0]].push_back({i, 0});
        }

        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (mp.find(s[i]) != mp.end())
            {

                vector<pair<int, int>> v = mp[s[i]];
                mp.erase(s[i]);
                for (int j = 0; j < v.size(); j++)
                {
                    int charInd = v[j].second;
                    int ind = v[j].first;
                    if (charInd + 1 == words[ind].length())
                    {
                        count++;
                    }
                    else
                    {
                        mp[words[ind][charInd + 1]].push_back({ind, charInd + 1});
                    }
                }
            }
        }
        return count;
    }
};