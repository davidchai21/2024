class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        if (_size >= dic.size()) {
            dic.push_back(val);
        }
        m[val] = _size++;
        return true;
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        int tail = dic[_size-1];
        m[tail] = m[val];
        swap(dic[m[val]], dic[_size-1]);
        dic.resize(_size-1);
        m.erase(val);
        --_size;
        return true;
    }
    
    int getRandom() {
        return dic[random()%_size];
    }
private:
    unordered_map<int, int> m;
    vector<int> dic;
    int _size = 0;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */