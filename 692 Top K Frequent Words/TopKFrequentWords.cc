class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (string& s : words) ++m[s];

        priority_queue<pair<string,int>, vector<pair<string, int>>, comp> pq;
        for (auto it = m.begin(); it != m.end(); ++it) {
            pq.push(make_pair(it->first, it->second));
            if (pq.size() > k) pq.pop();
        }

        vector<string> res(k);
        for (int i=k-1;i>=0;--i) {
            res[i] = pq.top().first;
            pq.pop();
        }
        return res;
    }
private:
    class comp {
    public:
        bool operator()(const pair<string,int>& lhs, const pair<string, int>& rhs) {
            return lhs.second > rhs.second || lhs.second == rhs.second && lhs.first < rhs.first;
        }
    };
};