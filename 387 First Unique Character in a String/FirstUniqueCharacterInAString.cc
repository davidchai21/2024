class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (char& c : s) ++m[c];
        for (int i=0;i<s.size();++i) {
            if (m[s[i]] == 1) return i;
        }
        return -1;
    }
};

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (int i=0;i<s.size();++i) {
            if (m.find(s[i]) == m.end()) m[s[i]] = i;
            else m[s[i]] = s.size();
        }
        int res = s.size();
        for (auto it = m.begin(); it != m.end(); ++it) {
            res = min(res, it->second);
        }
        return res == s.size() ? -1 : res;
    }
};