class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        
        int first = 0, last = 0;
        int left = 0;
        vector<bool> dic(256, 0);
        for (int i=0;i<s.size();++i) {
            if (!dic[s[i]]) dic[s[i]] = true;
            else {
                while (left < i && s[left] != s[i]) {
                    dic[s[left]] = false;
                    ++left;
                }
                if (left < i) ++left;
            }
            if (last - first < i - left) {
                last = i, first = left;
            }
        }
        if (last - first < s.size()-left-1) {
            last = s.size()-1;
            first = left;
        }
        return last-first+1;
    }
};