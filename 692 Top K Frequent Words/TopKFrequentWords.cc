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

// bucket sort:

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (string& word : words) ++m[word];
        vector<vector<string>> record(words.size()+1, vector<string>());
        for (auto it = m.begin(); it != m.end(); ++it) {
            record[it->second].push_back(it->first);
        }

        vector<string> res(k);
        for (int i=words.size(), s=0;i>=0;--i) {
            sort(record[i].begin(), record[i].end());
            for (string& word : record[i]) {
                res[s] = word;
                if (++s == k) return res;
            }
        }
        return res;
    }
};

// Quick select:

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (string& word : words) ++m[word];
        vector<pair<string, int>> record;
        for (auto it = m.begin(); it != m.end(); ++it) {
            record.push_back(make_pair(it->first, it->second));
        }

        int left = 0, right = record.size()-1;
        while (true) {
            int p = partition(record, left, right, k);
            if (p == k-1) break;
            else if (p > k-1) right = p-1;
            else left = p+1;
        }

        sort(record.begin(), record.begin()+k, [](const pair<string, int>& lhs, const pair<string, int>& rhs){
            return lhs.second > rhs.second || lhs.second == rhs.second && lhs.first < rhs.first;
        });
        vector<string> res(k);
        for (int i=0;i<k;++i) {
            res[i] = record[i].first;
        }
        return res;
    }
private:
    int partition(vector<pair<string, int>>& record, int left, int right, int k) {
        pair<string, int> pivot = record[right];
        int l = left, r = right-1;
        while (l <= r) {
            if ((record[l].second < pivot.second || record[l].second == pivot.second && record[l].first > pivot.first) && (record[r].second > pivot.second || record[r].second == pivot.second && record[r].first < pivot.first)) {
                swap(record[l++], record[r--]);
            } else {
                if (record[l].second > pivot.second || record[l].second == pivot.second && record[l].first < pivot.first) ++l;
                if (record[r].second < pivot.second || record[r].second == pivot.second && record[r].first > pivot.first) --r;
            }
        }
        swap(record[right], record[r+1]);
        return r+1;
    }
};