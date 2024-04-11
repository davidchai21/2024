class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int left = 0, right = s.size()-1;
        while (s[right] == '0' && right >= 0) --right;
        swap(s[right--], s.back());
        while (right > left) {
            if (s[right] == '1') {
                while (left < right && s[left] == '1') ++left;
                swap(s[left++], s[right]); 
            }
            --right;
        }
        return s;
    }
};