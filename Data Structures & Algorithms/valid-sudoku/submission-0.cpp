class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> s;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') continue;

                string num(1, board[i][j]);

                if (!s.insert(num + "r" + to_string(i)).second ||
                    !s.insert(num + "c" + to_string(j)).second ||
                    !s.insert(num + "b" + to_string((i/3)*3 + j/3)).second)
                    return false;
            }
        }
        return true;
    }
};
