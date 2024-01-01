class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i=0;
        int res = 0;
        for (int& c : g) {
            while (i < s.size() && c > s[i]) ++i;
            if (i == s.size()) break;
            ++res;
            ++i;
        }
        return res;
    }
};