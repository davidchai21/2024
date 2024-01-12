class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int count = 0;
        for (int i=0;i<n/2;++i) {
            char c = tolower(s[i]);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ++count;
            c = tolower(s[n-1-i]);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') --count;
        }
        return !count;
    }
};