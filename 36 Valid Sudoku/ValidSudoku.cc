class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> cells(9,0);
        for (int i=0;i<9;++i) {
            for (int j=0;j<9;++j) {
                if (board[i][j] != '.') {
                    int k = board[i][j] - '1';
                    // cell
                    if (cells[(i/3)*3+j/3] & 1<<(k+18)) return false;
                    cells[(i/3)*3+j/3] |= 1<<(k+18);
                    // row
                    if (cells[i] & 1<<k) return false;
                    cells[i] |= 1<<k;
                    // column
                    if (cells[j] & 1<<(k+9)) return false;
                    cells[j] |= 1<<(k+9);
                }
            }
        }
        return true;
    }
};