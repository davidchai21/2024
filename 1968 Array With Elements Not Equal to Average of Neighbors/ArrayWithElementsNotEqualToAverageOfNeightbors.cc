class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // a < b > c
        int i = 0;
        for (;i+2<nums.size();i += 2) {
            if (nums[i] < nums[i+1] && nums[i+1] < nums[i+2]) swap(nums[i+1], nums[i+2]);
            else if (nums[i] > nums[i+1] && nums[i+1] > nums[i+2]) swap(nums[i], nums[i+1]);
            else if (nums[i] > nums[i+1] && nums[i+1] < nums[i+2]) {
                swap(nums[i+1], nums[i]);
                if (nums[i+1] < nums[i+2]) swap(nums[i+1], nums[i+2]);
            }
        }
        if (i+2 == nums.size() && nums[i] > nums[i+1]) swap(nums[i], nums[i+1]);
        return nums;
    }
};

// something shorter, like wiggle sort:

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        for (int i=2;i<nums.size();++i) {
            if (nums[i] > nums[i-1] && nums[i-1] > nums[i-2] || nums[i] < nums[i-1] && nums[i-1] < nums[i-2]) swap(nums[i-1], nums[i]);
        }
        return nums;
    }
};