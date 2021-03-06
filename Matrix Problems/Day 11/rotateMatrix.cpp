    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        //Transpose
        for(int i=0; i<m; i++){
            for(int j=i; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //reverse columns
        for(int i=0; i<m; i++){
            for(int j=0; j<n/2; j++){
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }
