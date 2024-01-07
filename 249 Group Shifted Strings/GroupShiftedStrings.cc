class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> m;
        for (int i=0;i<strs.size();++i) {
            m[hash(strs[i])].push_back(i);
        }
        vector<vector<string>> res;
        for (auto it = m.begin(); it != m.end(); ++it) {
            res.push_back({});
            for (int i=0;i<it->second.size();++i) {
                res.back().push_back(strs[it->second[i]]);
            }
        }
        return res;
    }
private:
    string hash(string& s) {
        vector<int> dic(26, 0);
        for (char& c : s) {
            ++dic[c-'a'];
        }
        string res(s.size(), 'a');
        for (int index=0,i=0;i<26;++i) {
            while (dic[i]--) {
                res[index++] = 'a'+i;
            }
        }
        return res;
    }
};