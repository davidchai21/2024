class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        for (const int& num : nums) sum ^= num;
        int flag = 0;
        for (int i=0;i<32;++i) {
            if (sum & 1<<i) {
                flag = 1<<i;
                break;
            }
        }
        int one = 0, two = 0;
        for (const int& num : nums) {
            if (num & flag) {
                one ^= num;
            } else {
                two ^= num;
            }
        }
        return {one, two};
    }
};

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2, 0);
        long long sum = 0;
        for (const int& num : nums) {
            sum ^= num;
        }
        sum &= -sum;

        for (const int& num : nums) {
            if (sum & num) {
                res[0] ^= num;
            } else {
                res[1] ^= num;
            }
        }
        return res;
    }
};