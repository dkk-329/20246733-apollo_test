#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& board, int row, int col) {
        int m = board.size();
        int n = board[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col]!= 'O') return;
        board[row][col] = '#';
        dfs(board, row + 1, col);
        dfs(board, row - 1, col);
        dfs(board, row, col + 1);
        dfs(board, row, col - 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        // 处理第一行和最后一行
        for (int j = 0; j < n; j++) {
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }
        // 处理第一列和最后一列
        for (int i = 0; i < m; i++) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
int main() {
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    Solution solution;
    solution.solve(board);
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}