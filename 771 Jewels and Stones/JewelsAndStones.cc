class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<bool> dic(256, false);
        for (char& c : jewels) dic[c] = true;
        int res = 0;
        for (char& c : stones) {
            res += dic[c];
        }
        return res;
    }
};