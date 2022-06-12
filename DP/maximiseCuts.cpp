        vector<int> dp(n+1, INT_MIN);
        dp[0] = 0;
        vector<int> a = {x, y, z};
        for(int i=1; i<=n; i++){
            for(int j=0; j<3; j++){
                if(a[j] <= i){
                    int curr = dp[i - a[j]];
                    if(curr != INT_MIN)
                        dp[i] = max(dp[i], 1 + curr);
                }
            }
        }
        return dp[n] == INT_MIN ? 0 : dp[n];
    }
