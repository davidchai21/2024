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

// quick select:

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (int& num : nums) ++m[num];
        vector<pair<int, int>> record(m.begin(), m.end());
        quick_select(record, k);
        vector<int> res(k);
        for (int i=0;i<k;++i) res[i] = record[i].first;
        return res;
    }
private:
    void quick_select(vector<pair<int, int>>& nums, int k) {
        int left = 0, right = nums.size()-1;
        while (true) {
            int p = partition(nums, left, right);
            if (p == k-1) return;
            else if (p > k-1) right = p-1;
            else left = p+1;
        }
    }

    int partition(vector<pair<int, int>>& nums, int left, int right) {
        int pivot = nums[right].second;
        int l = left, r = right-1;
        while (l <= r) {
            if (nums[l].second < pivot && nums[r].second > pivot) swap(nums[l++], nums[r--]);
            else {
                if (nums[l].second >= pivot) ++l;
                if (nums[r].second <= pivot) --r;
            }
        }
        swap(nums[r+1], nums[right]);
        return r+1;
    }
};

// bucket sort:

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> buckets(n+1, vector<int>());
        unordered_map<int,int> m;
        for (int& num : nums) ++m[num];
        for (auto it = m.begin(); it != m.end(); ++it) {
            buckets[it->second].push_back(it->first);
        }
        
        vector<int> res(k);
        int index = 0;
        while (index < k) {
            for (int& num : buckets[n]) {
                res[index++] = num;
            }
            --n;
        }
        return res;
    }
};