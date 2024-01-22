class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        vector<int> d1(26, 0), d2(26, 0);
        int n = word1.size();
        for (int i=0;i<n;++i) {
            ++d1[word1[i]-'a'];
            ++d2[word2[i]-'a'];
        }

        unordered_map<int,int> m;
        for (int i=0;i<26;++i) {
            if (!d1[i] && d2[i] || d1[i] && !d2[i]) return false;
            if (d1[i]) {
                ++m[d1[i]];
                --m[d2[i]];
            }
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second) return false;
        }
        return true;
    }
};