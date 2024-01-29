class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if (s1.empty()) front = x;
        s1.push(x);
    }
    
    int pop() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int res = s2.top();
        s2.pop();
        if (!s2.empty()) front = s2.top();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return res;
    }
    
    int peek() {
        return front;
    }
    
    bool empty() {
        return s1.empty();
    }
private:
    stack<int> s1, s2;
    int front = -1;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


// better

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        helper();
        int res = s2.top();
        s2.pop();
        return res;
    }
    
    int peek() {
        helper();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
    stack<int> s1, s2;
    void helper() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */