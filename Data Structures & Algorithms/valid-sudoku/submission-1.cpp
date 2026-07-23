class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[10][10] = {false};
        bool col[10][10] = {false};
        bool sub_box[10][10] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int sb_index = (i / 3) * 3 + (j / 3);
                int value = board[i][j] - '0';

                
                if (row[i][value] == true)
                    return false;

                
                if (col[j][value] == true)
                    return false;

                if (sub_box[sb_index][value] == true)
                    return false;


                row[i][value] = true;
                col[j][value] = true;
                sub_box[sb_index][value] = true;

            }
        }
        

        return true;
    }
};
