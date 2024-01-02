class MyHashSet {
public:
    MyHashSet() {
        s.resize(_size);
    }
    
    void add(int key) {
        list<int>::iterator it = find(key);
        int index = key%_size;
        if (it != s[index].end()) return;
        s[index].push_back(key);
    }
    
    void remove(int key) {
        list<int>::iterator it = find(key);
        int index = key%_size;
        if (it != s[index].end()) {
            s[index].erase(it);
        }
    }
    
    bool contains(int key) {
        int index = key%_size;
        return find(key) != s[index].end();
    }
private:
    const size_t _size = 1337;
    vector<list<int>> s;

    list<int>::iterator find(int key) {
        int index = key%_size;
        list<int>::iterator it = s[index].begin();
        while (it != s[index].end()) {
            if (*it == key) break;
            ++it;
        }
        return it;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */