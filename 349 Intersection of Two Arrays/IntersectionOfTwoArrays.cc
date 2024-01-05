class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> res;
        for (const int& num : nums1) m[num] = 1;
        for (const int& num : nums2) {
            if (m.find(num) != m.end() && m[num] == 1) {
                res.push_back(num);
                m[num] = 2;
            }
        }
        return res;
    }
};

// hashset
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> res;
        for (const int& num : nums2) {
            if (s.find(num) != s.end()) {
                res.push_back(num);
                s.erase(num);
            }
        }
        return res;
    }
};