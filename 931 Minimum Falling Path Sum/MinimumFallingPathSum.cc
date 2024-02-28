class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=1;i<n;++i) {
            for (int j=0;j<n;++j) {
                matrix[i][j] += min(min(matrix[i-1][j], j ? matrix[i-1][j-1] : 10000), j == n-1 ? 10000 : matrix[i-1][j+1]);
            }
        }
        int res = matrix.back().front();
        for (int i=1;i<n;++i) {
            res = min(res, matrix.back()[i]);
        }
        return res;
    }
};