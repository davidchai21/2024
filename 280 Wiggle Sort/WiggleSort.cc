class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n-2) {
            if (nums[i] >= nums[i+1] && nums[i+1] >= nums[i+2]) {
                swap(nums[i], nums[i+1]);
            } else if (nums[i] <= nums[i+1] && nums[i+1] <= nums[i+2]) {
                swap(nums[i+1], nums[i+2]);
            } else if (nums[i] >= nums[i+1] && nums[i+1] <= nums[i+2]) {
                swap(nums[i], nums[i+1]);
                if (nums[i+1] < nums[i+2]) {
                    swap(nums[i+1], nums[i+2]);
                }
            }
            i += 2;
        }
        if (i+2 == n && nums[i] > nums[i+1]) swap(nums[i], nums[i+1]);
    }
};