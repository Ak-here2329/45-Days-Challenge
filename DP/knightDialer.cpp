    int mod = pow(10, 9) + 7;
    
    long helper(vector<vector<vector<long>>> &dp, int i, int j, int n){
        if(i < 0 || j < 0 || i >= 4 || j >= 3 || (i == 3 && j != 1))
            return 0;
        if(n == 1)
            return 1;
        
        if(dp[n][i][j] != -1)
            return dp[n][i][j];
        
        return dp[n][i][j] = helper(dp, i-1, j-2 , n-1) % mod + 
                             helper(dp, i-1, j+2 , n-1) % mod +
                             helper(dp, i+1, j-2 , n-1) % mod +
                             helper(dp, i+1, j+2 , n-1) % mod +
                             helper(dp, i-2, j-1 , n-1) % mod +
                             helper(dp, i-2, j+1 , n-1) % mod +
                             helper(dp, i+2, j-1 , n-1) % mod +
                             helper(dp, i+2, j+1 , n-1) % mod ;
    }
    
    int knightDialer(int n) {
        vector<vector<vector<long>>> dp(n+1, vector<vector<long>>(4, vector<long>(3, -1)));
        long ans = 0;
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                ans = (ans + helper(dp, i, j, n)) % mod;
            }
        }
        
        return ans;        
    }
