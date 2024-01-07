class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (int& num : nums) ++m[num];
        vector<pair<int,int>> record;
        for (auto it = m.begin(); it != m.end(); ++it) {
            record.push_back(make_pair(it->first, it->second));
        }
        sort(record.begin(), record.end(), [](const pair<int,int>& lhs, const pair<int,int>& rhs){
            return lhs.second > rhs.second;
        });
        
        vector<int> res(k);
        for (int i=0;i<k;++i) {
            res[i] = record[i].first;
        }
        return res;
    }
};