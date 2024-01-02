class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int& num : nums) {
            ++m[num];
        }
        vector<pair<int,int>> record;
        for (unordered_map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
            record.push_back(make_pair(it->first, it->second));
        }
        sort(record.begin(), record.end(), [](const pair<int,int>& lhs, const pair<int,int>& rhs){
            return lhs.second > rhs.second;
        });
        vector<vector<int>> res(record.front().second, vector<int>());
        for (pair<int,int>& rec : record) {
            for (int i=0;i<rec.second;++i) {
                res[i].push_back(rec.first);
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> m;
        int max_count = 0;
        for (int& num : nums) {
            max_count = max(max_count, ++m[num]);
        }

        vector<vector<int>> res(max_count, vector<int>());
        for (auto it = m.begin(); it != m.end(); ++it) {
            for (int i=0;i<it->second;++i) {
                res[i].push_back(it->first);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> m;
        for (int& i : nums) ++m[i];

        vector<vector<int>> res;
        for (auto it=m.begin(); it != m.end(); ++it) {
            for (int i=0;i<it->second;++i) {
                if (res.size() <= i) res.push_back({});
                res[i].push_back(it->first);
            }
        }
        return res;
    }
};