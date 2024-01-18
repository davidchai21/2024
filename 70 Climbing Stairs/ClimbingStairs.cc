class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        int one = 1, two = 2;
        for (int i=2; i<n;++i) {
            int t = one+two;
            one = two;
            two = t;
        }
        return two;
    }
};