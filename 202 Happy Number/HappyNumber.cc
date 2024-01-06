class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (n != 1) {
            if (s.find(n) != s.end()) return false;
            s.insert(n);
            n = digit(n);
        }
        return n == 1;
    }
private:
    int digit(int n) {
        int res = 0;
        while (n) {
            res += (n%10)*(n%10);
            n /= 10;
        }
        return res;
    }
};