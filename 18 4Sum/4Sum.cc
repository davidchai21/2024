class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i=0;i<n-3;++i) {
            for (int j=i+1;j<n-2;++j) {
                int left = j+1, right = n-1;
                long long sum = (long long)target-nums[i]-nums[j];
                while (left < right) {
                    if (nums[left]+nums[right] == sum) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left+1]) ++left;
                        while (left < right && nums[right] == nums[right-1]) --right;
                        ++left, --right;
                    } else if (nums[left]+nums[right] > sum) --right;
                    else ++left;
                }
                while (j < n-2 && nums[j] == nums[j+1]) ++j;
            }
            while (i < n-3 && nums[i] == nums[i+1]) ++i;
        }
        return res;
    }
};

// N Sum:

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> ans;
        nSum(target, 4, nums, 0, nums.size()-1, ans, res);
        return res;
    }
private:
    void nSum(long long sum, int n, vector<int>& nums, int left, int right, vector<int>& ans, vector<vector<int>>& res) {
        if (right-left+1 < n || sum > (long long)nums[right]*n || sum < (long long)nums[left]*n) return;
        if (n == 2) {
            int l = left, r = right;
            while (l < r) {
                if (nums[l]+nums[r] == sum) {
                    ans.push_back(nums[l]);
                    ans.push_back(nums[r]);
                    res.push_back(ans);
                    ans.pop_back();
                    ans.pop_back();
                    ++l, --r;
                    while (l < r && nums[l] == nums[l-1]) ++l;
                    while (l < r && nums[r] == nums[r+1]) --r;
                } else if (nums[l]+nums[r] < sum) ++l;
                else --r;
            }
            return;
        }

        for (int i=left; i < right-n+2;++i) {
            ans.push_back(nums[i]);
            nSum(sum-nums[i], n-1, nums, i+1, right, ans, res);
            ans.pop_back();
            while (i < right-n+2 && nums[i] == nums[i+1]) ++i;
        }
    }
};