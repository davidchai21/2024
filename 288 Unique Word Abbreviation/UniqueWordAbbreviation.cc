class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (string& s : dictionary) {
            m[helper(s)].insert(s);
        }
    }
    
    bool isUnique(string word) {
        string abbr = helper(word);
        if (m.find(abbr) == m.end() || m[abbr].find(word) != m[abbr].end() && m[abbr].size() == 1) return true;
        return false;
    }
private:
    string helper(string& s) {
        if (s.size() < 3) return s;
        return string(1, s.front())+to_string(s.size()-2)+string(1, s.back());
    }
    
    unordered_map<string, unordered_set<string>> m;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */