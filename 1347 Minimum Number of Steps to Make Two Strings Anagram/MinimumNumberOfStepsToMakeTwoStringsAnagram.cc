class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> record(26, 0);
        for (char&c : s) ++record[c-'a'];
        for (char&c : t) --record[c-'a'];
        int res = 0;
        for (int& k : record) {
            if (k > 0) res += k;
        }
        return res;
    }
};