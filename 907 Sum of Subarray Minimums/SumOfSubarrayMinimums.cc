class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        vector<int> record(arr.size()+1, 0);
        int res = 0;
        for (int i=0;i<arr.size();++i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (st.empty()) {
                record[i+1] = (i+1)*arr[i];
            } else {
                record[i+1] = record[st.top()+1] + arr[i]*(i-st.top());
            }
            record[i+1] %= mod;
            st.push(i);
            res = (res+record[i+1])%mod;
        }
        return res;
    }
private:
    const int mod = 1e9+7;
};