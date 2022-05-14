    bool valid(int i, int j, int m, int n){
        if(i >=0 && j >=0 && i < m && j < n)
            return true;
        return false;
    }
    
    bool corner(int i, int j, int m, int n){
        if(i == 0 || j == 0 || i == m-1 || j== n-1)
            return true;
        return false;
    }
    
    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &visited){
        if(grid[i][j] == 'X')
            return;
        
        int di[] = {-1, 1, 0, 0};
        int dj[] = {0, 0, -1, 1};
        int m = grid.size(), n = grid[0].size();
        
        visited[i][j] = true;
        grid[i][j] = '#';
        
        for(int k=0; k<4; k++){
            int x = i + di[k];
            int y = j + dj[k];
            if(valid(x, y, m, n) and !visited[x][y])
                dfs(grid, x, y, visited);
        }
    }
    
    vector<vector<char>> fill(int m, int n, vector<vector<char>> mat)
    {
        // code here
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(corner(i, j, m, n) && mat[i][j] == 'O' && !visited[i][j])
                    dfs(mat, i, j, visited);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == '#')
                    mat[i][j] = 'O';
                else
                    mat[i][j] = 'X';
            }
        }
        return mat;
    }
