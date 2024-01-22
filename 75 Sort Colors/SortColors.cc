class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        while (left < right) {
            if (!nums[left]) {
                ++left;
                continue;
            }
            if (!nums[right]) {
                swap(nums[left], nums[right]);
            }
            --right;
        }
        if (left == n) return;
        if (!nums[left]) {
            ++left, ++right;
        }
        while (left < n) {
            if (nums[left] == 1) {
                swap(nums[left], nums[right++]);
            }
            ++left;
        }
    }
};

// One pass:

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i=0, j=0, k=nums.size()-1; j <= k;++j) {
            if (nums[j] == 2) {
                swap(nums[j], nums[k--]);
                --j;
            } else if (!nums[j]) {
                swap(nums[j], nums[i++]);
            }
        }
    }
};