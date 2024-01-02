class MyHashMap {
public:
    MyHashMap() {
        m.resize(_size);
    }
    
    void put(int key, int value) {
        int index = key%_size;
        Node* n = find(index, key);
        if (n) n->val = value;
        else {
            if (m[index]) {
                Node* new_node = new Node(key, value);
                new_node->next = m[index];
                m[index] = new_node;
            } else {
                m[index] = new Node(key, value);
            }
        }
    }
    
    int get(int key) {
        int index = key%_size;
        Node* n = find(index, key);
        return n ? n->val : -1;
    }
    
    void remove(int key) {
        int index = key%_size;
        if (m[index]) {
            if (m[index]->key == key) m[index] = m[index]->next;
            else {
                Node* cur = m[index];
                while (cur->next) {
                    if (cur->next->key == key) break;
                    cur = cur->next;
                }
                if (cur->next) {
                    cur->next = cur->next->next;
                }
            }
        }
    }
private:
    struct Node {
        int key = 0;
        int val = 0;
        Node* next = nullptr;

        Node() {}
        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
        ~Node() {
            if (this->next) {
                delete this->next;
                this->next = nullptr;
            }
        }
    };

    Node* find(int& index, int& key) {
        Node* cur = m[index];
        while (cur) {
            if (cur->key == key) break;
            cur = cur->next;
        }
        return cur;
    }

    const size_t _size = 1337;
    vector<Node*> m;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */