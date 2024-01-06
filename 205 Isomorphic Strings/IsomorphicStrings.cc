class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> d1(256, -1), d2(256, -1);
        for (int i=0;i<s.size();++i) {
            if (d1[s[i]] == -1 && d2[t[i]] == -1) {
                d1[s[i]] = t[i];
                d2[t[i]] = s[i];
            } else if (d1[s[i]] == -1 || d2[t[i]] == -1) {
                return false;
            } else {
                if (d1[s[i]] != t[i] || d2[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};