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

