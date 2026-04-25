class Solution {
private:
    string str;
    char vis[300];
    vector<string> dc;
    bool sl(int i)
    {
        if (i == str.size()) return true;
        if (vis[i]) return false;
        vis[i] = 1;
        for (int d = 0; d < dc.size(); d++)
        {
            if (str.find(dc[d], i) == i)
            {
                if (sl(i+dc[d].size()) == true)
                    return true;
            }
        }
        return false;
    }
    static bool cmp(string a, string b)
    {
        return a.size() > b.size();
    }
public:
// applepenapple
    bool wordBreak(string s, vector<string>& wordDict) {
        dc = wordDict;
        str = s;
        return sl(0);
    }
};