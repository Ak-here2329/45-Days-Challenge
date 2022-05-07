    bool isValid(int i, int j, int m, int n){
        if(i >= 0 && j >= 0 && i < m && j < n)
            return true;
        return false;
    }
    
    bool change0(vector<vector<int>> &copy, int i, int j){
        int zero = 0, one = 0;
        int m = copy.size(), n = copy[0].size();
        int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        for(int k=0; k<8; k++){
            int x = i + dy[k];
            int y = j + dx[k];
            if(isValid(x, y, m, n))
                copy[x][y] == 0 ? zero++ : one++;
        }
        
        if(one == 3)
            return true;
        return false;
    }
    
    bool change1(vector<vector<int>> &copy, int i, int j){
        int zero = 0, one = 0;
        int m = copy.size(), n = copy[0].size();
        int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        for(int k=0; k<8; k++){
            int x = i + dy[k];
            int y = j + dx[k];
            if(isValid(x, y, m, n))
                copy[x][y] == 0 ? zero++ : one++;
        }
        
        if(one < 2 || one > 3)
            return true;
        return false;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> copy = board;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 0 && change0(copy, i, j))
                    board[i][j] = 1;
                else if (board[i][j] == 1 && change1(copy, i, j))
                    board[i][j] = 0;
            }
        }
    }
