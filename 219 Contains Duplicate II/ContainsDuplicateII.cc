class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (int i=0;i<nums.size();++i) {
            if (m.find(nums[i]) != m.end()) {
                if (i - m[nums[i]] <= k) return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};


// using hashset
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        for (int i=0;i<nums.size();++i) {
            if (i>k) s.erase(nums[i-k-1]);
            if (s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};