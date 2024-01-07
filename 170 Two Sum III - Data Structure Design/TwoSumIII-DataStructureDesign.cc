class TwoSum {
public:
    TwoSum() {
        
    }
    
    void add(int number) {
        ++m[number];
    }
    
    bool find(int value) {
        for (auto it = m.begin(); it != m.end(); ++it) {
            long long diff = value - it->first;
            if (diff == it->first) {
                if (it->second > 1) return true;
            } else {
                if (m.find(diff) != m.end()) return true;
            }
        }
        return false;
    }
private:
    unordered_map<long long, int> m;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */