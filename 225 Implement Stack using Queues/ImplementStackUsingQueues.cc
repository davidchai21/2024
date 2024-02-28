class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size = q.size();
        while (size > 1) {
            q.push(q.front());
            q.pop();
            --size;
        }
        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() {
        int size = q.size();
        while (size > 1) {
            q.push(q.front());
            q.pop();
            --size;
        }
        int res = q.front();
        q.push(res);
        q.pop();
        return res;
    }
    
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// another:

class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for (int i=0;i<q.size()-1;++i) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */