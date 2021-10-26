class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string word, int k) {
        if (board[i][j] != word[k]) {
            return false;
        } else if (k == word.length() - 1) {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (const auto& direction: directions) {
            int newI = i + direction.first, newJ = j + direction.second;
            if (newI >= 0 && newI < board.size() && newJ >= 0 && newJ < board[0].size()) {
                if (!visited[newI][newJ]) {
                    bool flag = check(board, visited, newI, newJ, word, k + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }
};