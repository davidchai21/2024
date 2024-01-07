class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int,int> m;
        for (int i=0;i<n;++i) {
            for (int j=0;j<n;++j) {
                ++m[nums3[i]+nums4[j]];
            }
        }
        
        int res = 0;
        for (int i=0;i<nums1.size();++i) {
            for (int j=0;j<nums2.size();++j) {
                int diff = -nums1[i]-nums2[j];
                if (m.find(diff) != m.end()) res += m[diff];
            }
        }
        return res;
    }
};