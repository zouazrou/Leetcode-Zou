class Solution {
public:
    void prr(set<char>& s)
    {
        for (auto it = s.begin(); it != s.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    int lengthOfLongestSubstring(string s) {
        size_t mx = 0;
        vector<char> alph;
        vector<char>::iterator it;
        for (int i = 0; i < s.size(); i++) {
            if ((it = find(alph.begin(), alph.end(), s[i])) != alph.end()) {
                mx = max(mx, alph.size());
                alph.erase(alph.begin(), ++it);
                // prr(alph);
            }
            alph.push_back(s[i]);
        }
        return max(mx, alph.size());
    }
};