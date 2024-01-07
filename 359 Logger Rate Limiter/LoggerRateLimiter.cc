class Logger {
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (m.find(message) != m.end()) {
            if (timestamp - m[message] < _interval) return false;
        }
        m[message] = timestamp;
        return true;
    }
private:
    unordered_map<string, int> m;
    const int _interval = 10;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */