class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cmp = [](const int& a, const int& b){
            return a > b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq;
        for (int& num : nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int& num : nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};

// quick select:

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        while (true) {
            int p = partition(nums, left, right);
            if (p == k-1) return nums[p];
            else if (p < k-1) left = p+1;
            else right = p-1;
        }
    }
private:
    int partition(vector<int>& nums, const int& left, const int& right) {
        int index = left + rand()%(right-left+1);
        swap(nums[left], nums[index]);
        return helper(nums, left, right);
    }

    int helper(vector<int>& nums, const int& left, const int& right) {
        int pivot = nums[left];
        int l = left+1;
        int r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            } else {
                if (nums[l] >= pivot) ++l;
                if (nums[r] <= pivot) --r;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
};