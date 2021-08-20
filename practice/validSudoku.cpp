class Solution {
public:
    bool checkRow(int i, int j, vector<vector<char>> &board){
        for(int k = 0; k < 9;k++){
            if(board[i][k] == board[i][j] && k != j)
                return false;
        }
        
        return true;
    }
    
    
    bool checkCol(int i, int j, vector<vector<char>> &board){
        for(int k = 0; k < 9; k++){
            if(board[k][j] == board[i][j] && k != i)
                return false;
        };
        
        return true;
    }
    
    bool checkBox(int i, int j, vector<vector<char>> &board){
        int x = i/3, y = j/3;
        
        for(int xx = x*3; xx < x*3+3; xx++){
            for(int yy = y*3; yy < y*3+3; yy++){
                if(board[xx][yy] == board[i][j] && xx != i && yy != j)
                    return false;
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(!checkRow(i,j,board) || !checkCol(i,j,board) || !checkBox(i,j,board))
                        return false;
                }
            }
        }
        
        return true;
                
    }
};