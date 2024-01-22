class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> m;
        for (vector<int>& match : matches) {
            m[match[0]];
            ++m[match.back()];
        }

        vector<vector<int>> res(2, vector<int>());
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second == 0) res[0].push_back(it->first);
            else if (it->second == 1) res[1].push_back(it->first);
        }
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        return res;
    }
};