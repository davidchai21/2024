class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int &num : nums) {
            ++m[num];
        }

        int res = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second == 1) return -1;
            res += 2*(it->second/6);
            if (it->second%6 == 0) continue;
            res += it->second%6 > 3 ? 2 : 1;
        }
        return res;
    }
};