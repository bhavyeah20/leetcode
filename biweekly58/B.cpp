class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        
        //right
        for(int j = cMove+1; j < 8; j++){
            if(board[rMove][j] == '.')
                break;

            else if(board[rMove][j] == color){
                if(j-cMove >= 2)
                return true;

                else 
                    break;
            }

        }


        //right down
        for(int j = cMove+1, i = rMove+1; j < 8 && i < 8; i++,j++){
            if(board[i][j] == '.')
                break;

            else if(board[i][j] == color){
                if(j-cMove >= 2 && i-rMove >=2)
                return true;

                else 
                    break;
            }

        }

        //down
        for(int i = rMove+1; i < 8; i++){
            if(board[i][cMove] == '.')
                break;

            else if(board[i][cMove] == color){
                if(i-rMove >= 2)
                return true;

                else 
                    break;
            }

        }

       //left down
        for(int j = cMove-1, i = rMove+1; j >= 0 && i < 8; i++,j--){
            if(board[i][j] == '.')
                break;

            else if(board[i][j] == color){
                if(abs(j-cMove) >= 2 && i-rMove >=2)
                return true;

                else 
                    break;
            }

        }

        //left
          for(int j = cMove-1; j >= 0; j--){
            if(board[rMove][j] == '.')
                break;

            else if(board[rMove][j] == color){
                if(abs(j-cMove) >= 2)
                return true;

                else 
                    break;
            }

        }

        //leftup
      for(int j = cMove-1, i = rMove-1; j >= 0 && i >= 0; i--,j--){
            if(board[i][j] == '.')
                break;

            else if(board[i][j] == color){
                if(abs(j-cMove) >= 2 && abs(i-rMove) >=2)
                return true;

                else 
                    break;
            }

        }

        //up
        for(int i = rMove-1; i >= 0; i--){
            if(board[i][cMove] == '.')
                break;

            else if(board[i][cMove] == color){
                if(abs(i-rMove) >= 2)
                return true;

                else 
                    break;
            }

        }

        //right up
        for(int j = cMove+1, i = rMove-1; j < 8 && i >= 0; i--,j++){
            if(board[i][j] == '.')
                break;

            else if(board[i][j] == color){
                if(j-cMove >= 2 && abs(i-rMove) >=2)
                return true;

                else 
                    break;
            }

        }

        return false;

    }
};