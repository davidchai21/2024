class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string, int> m1, m2;
        for (int i=0;i<list1.size();++i) m1[list1[i]] = i;
        for (int i=0;i<list2.size();++i) m2[list2[i]] = i;
        
        int sum = INT_MAX;
        for (string& s : list1) {
            if (m2.find(s) != m2.end()) {
                int new_sum = m2[s] + m1[s];
                if (sum > new_sum) {
                    sum = new_sum;
                    res = {s};
                } else if (sum == new_sum) {
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string, int> m;
        for (int i=0;i<list1.size();++i) m[list1[i]] = i;
        int sum = list1.size() + list2.size();
        for (int i=0;i<list2.size();++i) {
            if (m.find(list2[i]) != m.end()) {
                int new_sum = i+m[list2[i]];
                if (new_sum < sum) {
                    sum = new_sum;
                    res = {list2[i]};
                } else if (new_sum == sum) {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};